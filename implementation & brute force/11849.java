
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
		int ans = 0;
		Set<Integer> occ = new HashSet<>();
		while ( l[0] != 0 || l[0] != 0 ){
			ans = 0;
			occ.clear();
			for ( int k = 0; k < l[0]; k++){
				int temp = Integer.parseInt(gi.readLine());
				occ.add(temp);
			}for ( int k = 0; k < l[1]; k++){
				int temp = Integer.parseInt(gi.readLine());
				if ( occ.contains(temp) ){ ans++; }
			}
			go.println(ans);
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
