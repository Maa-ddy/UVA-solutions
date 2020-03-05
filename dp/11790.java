/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import static java.lang.Math.*;
import java.math.*;

public class Main{

	static PrintWriter go = new PrintWriter(System.out);
	
	public static void main(String args[]) throws IOException,FileNotFoundException {
		BufferedReader gi = new BufferedReader(new InputStreamReader(System.in, "ISO-8859-1"));
		int t = Integer.parseInt(gi.readLine());
		for ( int cas = 1; cas <= t; cas++ ){
			int n = Integer.parseInt(gi.readLine());
			int[] a = parseArray(gi);
			int[] b = parseArray(gi);
			int[] dp = new int[n];
			dp[0] = b[0];
			int ans = dp[0];
			for ( int k = 1; k < n; k++ ){
				dp[k] = b[k];
				for ( int j = 0; j < k; j++ ){
					if (a[j] < a[k]) dp[k] = max(dp[k], b[k] + dp[j]);
				}
				ans = max(ans, dp[k]);
			}
			Arrays.fill(dp, 0);
			dp[0] = b[0];
			int ans2 = dp[0];
			for ( int k = 1; k < n; k++ ){
				dp[k] = b[k];
				for ( int j = 0; j < k; j++ ){
					if (a[j] > a[k]) dp[k] = max(dp[k], b[k] + dp[j]);
				}
				ans2 = max(ans2, dp[k]);
			}
			if (ans >= ans2)
				go.println("Case " + cas + ". Increasing (" + ans + "). Decreasing (" + ans2 + ").");
			else
				go.println("Case " + cas + ". Decreasing (" + ans2 + "). Increasing (" + ans + ").");
		}
		go.close();
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


