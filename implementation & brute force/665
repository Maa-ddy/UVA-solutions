import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import java.math.*;

public class Main{

	static PrintWriter go = new PrintWriter(System.out);

	public static void main(String args[]) throws IOException,FileNotFoundException {
		BufferedReader gi = new BufferedReader(new InputStreamReader(System.in));
		int m = Integer.parseInt(gi.readLine());
		for ( int k = 0; k < m; k++){
			gi.readLine();
			int[] temp = parseArray(gi);
			int n = temp[0];
			int K = temp[1];
			boolean[] ans = new boolean[n+1];
			for ( int j = 0; j < K; j++){
				int[] line = parseArray(gi);
				if ( gi.readLine().equals("=") ){
					for ( int i = 1; i <= 2*line[0]; i++){
						ans[line[i]] = true;
					}
				}
			}
			int count = 0;
			int rez = 0;
			for ( int j = 1; j < n+1; j++){
				if ( !ans[j] ){
					if ( rez == 0 ){ rez = j; }
					count++;
				}
			}
			if ( count == 1 ){ go.println(rez); }
			else{ go.println(0); }
			if ( k != m-1 )go.println();
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
