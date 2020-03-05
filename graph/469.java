/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
//Graph, dfs, dp, implementation
import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import java.math.*;

public class Main{

	static PrintWriter go = new PrintWriter(System.out);
	static char[][] g = new char[111][111];
	static boolean[][] vis = new boolean[111][111];
	static int[][] dp = new int[111][111];
	static int n, m;

	public static void main(String args[]) throws IOException,FileNotFoundException {
		BufferedReader gi = new BufferedReader(new InputStreamReader(System.in, "ISO-8859-1"));
		int t = Integer.parseInt(gi.readLine());
		String s = gi.readLine();
		for ( int k = 1; k <= t; k++ ){
			String[] line = gi.readLine().split(" ");
			m = line[0].length(); n = 0;
			while (line.length == 1) {
				g[n++] = line[0].toCharArray();
				line = gi.readLine().split(" ");
			}
			List<int[]> queries = new ArrayList<>();
			while (line.length == 2) {
				int[] q = new int[2];
				q[0] = Integer.parseInt(line[0]) - 1;
				q[1] = Integer.parseInt(line[1]) - 1;
				queries.add(q);
				s = gi.readLine();
				if (s == null)
					break;
				line = s.split(" ");
			}
			for ( int j = 0; j < n; j++ )
				for ( int i = 0; i < m; i++ ) {
					vis[j][i] = false;
					dp[j][i] = -1;
				}
			for (int[] query : queries) {
				int x = query[0], y = query[1];
				int ans = 0;
				if (vis[x][y])
					ans = dp[x][y];
				else {
					ans = dfs(x, y);
					equalize(x, y, ans);
				}
				go.println(ans);
			}
			if (k < t)
				go.println();
		}
		go.close();
	}

	static int dfs(int x, int y) {
		if (x >= n || x < 0 || y >= m || y < 0)
			return 0;
		if (g[x][y] == 'L')
			return dp[x][y] = 0;
		if (dp[x][y] == -2)
			return 0;
		if (dp[x][y] != -1)
			return 0;
		dp[x][y] = -2;
		int ans = 1;
		for ( int k = -1; k <= 1; k++ )
			for ( int j = -1; j <= 1; j++ )
				ans += dfs(x + k, y + j);
		return dp[x][y] = ans;
	}

	static void equalize(int x, int y, int v) {
		if (x >= n || x < 0 || y >= m || y < 0)
			return;
		if (vis[x][y])
			return;
		if (g[x][y] == 'L')
			return;
		vis[x][y] = true;
		dp[x][y] = v;
		for ( int k = -1; k <= 1; k++ )
			for ( int j = -1; j <= 1; j++ )
				equalize(x + k, y + j, v);
	}

	static int[] parseArray(BufferedReader gi) throws IOException{
		String[] line = gi.readLine().split(" ");
		int[] rez = new int[line.length];
		for ( int k = 0; k < line.length; k++){
			rez[k] =  Integer.parseInt(line[k]);
		}
		return rez;
	}

}
