
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
		int T = Integer.parseInt(gi.readLine());
		int width, pos;
		int[] l;
		int temp,ans;
		for ( int k = 0; k < T; k++){
			l = parseArray(gi);
			width = l[0];
			pos = l[1];
			ans = 0;
			while ( width > 0 ){
				temp = (pos/(1<<width-1)+1)%4;
				if ( temp == 2 || temp == 3 ){ ans |= 1<<(width-1); }
				width--;
			}
			go.println(ans);
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
