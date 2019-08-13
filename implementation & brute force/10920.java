import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import java.math.*;

public class Main{

	static PrintWriter go = new PrintWriter(System.out);

	public static void main(String args[]) throws IOException,FileNotFoundException {
		BufferedReader gi = new BufferedReader(new InputStreamReader(System.in));
		long[] l = parseArray(gi);
		long sz = l[0];
		long p = l[1];
		while ( sz != 0 || p != 0 ){
			long pos = 1;
			long col = sz/2 + 1;
			long line = col;
			boolean flag = true;
			long delta = 1;
			long mult = 1;
			while ( true ){
				if ( p >= pos && p <= pos + delta ){
					if ( flag ){
						line += (p - pos)*mult;
					}else{
						mult *= -1;
						col += (p - pos)*mult;
					}
					break;
				}
				pos += delta;
				if ( flag ){
					line += delta*mult;
					flag = false;
				}else{
					mult *= -1;
					col += delta*mult;
					delta += 1;
					flag = true;
				}
			}
			go.println("Line = " + line + ", column = " + col + ".");
			l = parseArray(gi);
			sz = l[0];
			p = l[1];
		}
		go.close();
	}

	static long[] parseArray(BufferedReader gi) throws IOException{
		String[] line = gi.readLine().trim().split(" ");
		long[] rez = new long[line.length];
		for ( int k = 0; k < line.length; k++){
			rez[k] = Long.parseLong(line[k]);
		}
		return rez;
	}

}
