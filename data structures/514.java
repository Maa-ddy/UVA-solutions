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
		int n = Integer.parseInt(gi.readLine());
		while (n != 0) {
			int[] a = parseArray(gi);
			while (a[0] != 0) {
				solve(n, a);
				a = parseArray(gi);
			}go.println();
			n = Integer.parseInt(gi.readLine());
		}
		go.close();
	}

	static void solve(int n, int[] a) {
		Stack<Integer> st = new Stack<>();
		int cur = 0;
		for ( int k = 1; k <= n; k++ ){
			st.push(k);
			while (!st.isEmpty() && st.peek() == a[cur]) {
				st.pop();
				cur++;
			}
		}
		if (st.isEmpty()) go.println("Yes");
		else go.println("No");
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


