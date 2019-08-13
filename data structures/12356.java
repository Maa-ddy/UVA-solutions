
import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import static java.lang.Math.*;
import java.math.*;

 class Main{

	static PrintWriter go = new PrintWriter(System.out);

	public static void main(String args[]) throws IOException,FileNotFoundException {
		BufferedReader gi = new BufferedReader(new InputStreamReader(System.in));
		int[] l = parseArray(gi);
		int[] q;
		int S,B,le,ri;
		while ( l[0] != 0 || l[1] != 0 ){
			S = l[0];
			B = l[1];
			int[] left = new int[S+2];
			int[] right = new int[S+2];
			for ( int k = 0; k < S+2; k++){
				left[k] = k;
				right[k] = k;
			}
			for ( int k = 0; k < B; k++){
				q = parseArray(gi);
				le = q[0] - 1;
				ri = q[1] + 1;
				for ( int j = le+1; j < ri; j++){
					left[j] = le;
					right[j] = ri;
				}
				int temp;
				while ( left[le] != le && le != 0 ){ 
					temp = left[le];
					left[le] = left[left[le]];
					le = temp;
				}
				go.print(le == 0?"* ":le+" ");
				while ( right[ri] != ri && ri != S+1 ){
					temp = right[ri];
					right[ri] = right[temp];
					ri = temp;
				}
				go.print(ri == S+1?"*":ri);
				go.println();
			}
			go.println("-");

			l = parseArray(gi);
		}
		go.close();
	}

	static int[] parseArray(BufferedReader gi) throws IOException{
		String[] line = gi.readLine().trim().split(" ");
		int[] rez = new int[line.length];
		for ( int k = 0; k < line.length; k++){
			rez[k] = Integer.parseInt(line[k]);
		}
		return rez;
	}

}
