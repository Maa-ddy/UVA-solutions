//uva 11340
/*
veeeeeeeeeeeeeeeeeeeerrrrrrrrryyyyyyyyyyyyy interesting
*/
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
		int n;
		int T = Integer.parseInt(gi.readLine());
		char[] s;
		double ans;
		while (T-- != 0){
			double[] m = new double[3000];
			n = Integer.parseInt(gi.readLine());
			while (n-- != 0){
				String[] line = gi.readLine().split(" ");
				m[line[0].charAt(0)] = Double.parseDouble(line[1]);
			}
			ans = 0;
			n = Integer.parseInt(gi.readLine());
			while (n-- != 0){
				s = gi.readLine().toCharArray();
				for ( int k = 0; k < s.length; k++ ){
					ans += m[s[k]];
				}
			}
			go.printf("%.2f$\n", ans/100);
		}
		go.close();
	}

	static int[] parseArray(BufferedReader gi) throws IOException{
		String[] line = gi.readLine().split(" ");
		int[] rez = new int[line.length];
		for ( int k = 0; k < line.length; k++){
			rez[k] = Integer.parseInt(line[k]);
		}
		return rez;
	}

}
