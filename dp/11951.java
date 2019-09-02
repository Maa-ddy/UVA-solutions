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
		int[] l;
		int cas = 1;
		while (t-- > 0) {
			l = parseArray(gi);
			int n = l[0], m = l[1], p = l[2];
			int[][] mat = new int[n][];
			for ( int k = 0; k < n; k++ ){
				mat[k] = parseArray(gi);
			}
			long[][] pref = new long[n][m];
			for ( int k = 0; k < n; k++ ){
				pref[k][0] = mat[k][0];
				for ( int j = 1; j < m; j++ ){
					pref[k][j] = pref[k][j - 1] + mat[k][j];
				}
			}
			int ans = 0;
			long s = 0;
			for ( int k = 0; k < m; k++ ){
				for ( int j = k; j < m; j++ ){
					long ss = 0;
					int start = 0;
					for ( int i = 0; i < n; i++ ){
						ss += sum(i, k, j, pref);
						while (ss > p) {
							ss -= sum(start, k, j, pref);
							start++;
						}
						int area = (j - k + 1) * (i - start + 1);
						if (area > ans) {
							ans = area;
							s = ss;
						}else if (area == ans) {
							s = min(s, ss);
						}
					}
				}
			}
			go.println("Case #" + cas++ + ": " + ans + " " + s);
		}
		go.close();
	}

	static long sum(int k, int start, int end, long[][] pref) {
		if (start == 0) return pref[k][end];
		return pref[k][end] - pref[k][start - 1];
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


