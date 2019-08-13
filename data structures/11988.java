
import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import static java.lang.Math.*;
import java.math.*;

public class Main{

	static PrintWriter go = new PrintWriter(System.out);

	public static void main(String args[]) throws IOException,FileNotFoundException {
		BufferedReader gi = new BufferedReader(new InputStreamReader(System.in));
		String line = gi.readLine();
		LinkedList<String> ans = new LinkedList<>();
		StringBuilder sb = new StringBuilder();
		int cur, len, last;
		while ( !line.equals("") ){
			cur = 0;
			len = line.length();
			last = 0;
			ans.clear();
			sb = new StringBuilder();
			while ( cur < len ){
				if ( line.charAt(cur) == '[' ){
					if ( last == 0 ){
						ans.add(sb.toString());
						sb = new StringBuilder();
					}else {
						ans.addFirst(sb.toString());
						sb = new StringBuilder();
					}
					last = 1;
				}else if ( line.charAt(cur) == ']' ){
					if ( last == 1 ){
						ans.addFirst(sb.toString());
						sb = new StringBuilder();
					}
					last = 0;
				}else{
					sb.append(line.charAt(cur));
				}
				cur++;
			}
			if ( last == 0 ){ ans.add(sb.toString()); }
			else{ ans.addFirst(sb.toString()); }
			for ( String s : ans ){
				go.print(s);
			}go.println();
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
