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
		int q = Integer.parseInt(gi.readLine());
		for ( int k = 0; k < q; k++ ){
			int n = Integer.parseInt(gi.readLine().trim()) - 1;
			int[] a = new int[n];
			for ( int j = 0; j < n; j++ ){
				a[j] = Integer.parseInt(gi.readLine().trim());
			}
			long mx;
			long[][] ans = new long[n][2];
			mx = ans[0][0] = a[0];
			ans[0][1] = 1;
			for ( int j = 1; j < n; j++ ){
				if (ans[j - 1][0] + a[j] >= a[j]) {
					ans[j][0] = ans[j - 1][0] + a[j];
					ans[j][1] = ans[j - 1][1] + 1;
				}else {
					ans[j][0] = a[j];
					ans[j][1] = 1;
				}
				mx = max(mx, ans[j][0]);
			}
			if (mx < 0) {
				go.println("Route " + (k + 1) + " has no nice parts");
			}else {
				int idx = -1;
				for ( int j = 0; j < n; j++ ){
					if (ans[j][0] == mx) {
						if (idx == -1)idx = j;
						else if (ans[j][1] > ans[idx][1])idx = j;
					}
				}
				go.println("The nicest part of route " + (k + 1) + " is between stops " + (idx - ans[idx][1] + 2) + " and " + (idx + 2));
			}
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
