

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
		String line = gi.readLine();
		char[] l;
		int[] map = new int[1000];
		map['B'] = 1; map['F'] = 1; map['P'] =1; map['V'] = 1;
		map['C'] =2; map['G'] =2; map['J'] =2; map['K'] =2; map['Q'] =2; map['S'] =2; map['X'] =2; map['Z'] = 2;
		map['D'] =3; map['T'] = 3;
		map['L'] = 4;
		map['M'] =5; map['N'] = 5;
		map['R'] = 6;
		StringBuilder ans;
		while ( line != null ){
			l = line.toCharArray();
			ans = new StringBuilder();
			if ( map[l[0]] != 0 ){ ans.append(map[l[0]]+""); }
			for ( int k = 1; k < l.length; k++){
				if ( map[l[k]] != 0 && map[l[k]] != map[l[k-1]] ){
					ans.append(map[l[k]]+"");
				}
			}
			go.println(ans.toString());
			line = gi.readLine();
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
