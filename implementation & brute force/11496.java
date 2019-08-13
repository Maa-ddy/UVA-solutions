

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
		int n = Integer.parseInt(gi.readLine());
		int[] l;
		int ans = 0;
		while ( n != 0 ){
			l = parseArray(gi);
			ans = 0;
			if ( l[0] >l[n-1] && l[0] > l[1] || l[0] < l[n-1] && l[0] < l[1] ){ ans++; }
			if ( l[0] >l[n-1] && l[n-2] > l[n-1] || l[0] < l[n-1] && l[n-2] < l[n-1] ){ ans++; }
			for ( int k = 1; k < n-1; k++){
				if ( l[k] >l[k-1] && l[k] > l[k+1] || l[k] < l[k-1] && l[k] < l[k+1] ){ ans++; }
			}
			go.println(ans);
			n = Integer.parseInt(gi.readLine());
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
