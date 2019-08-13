
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
		int[] l,fuel,need;
		long sum;
		int ans,N;
		boolean flag;
		for ( int k = 0; k < n; k++){
			N = Integer.parseInt(gi.readLine());
			StringTokenizer st = new StringTokenizer( gi.readLine() );
			fuel = new int[N];
			need = new int[N];
			for ( int j = 0; j < N; j++){
				if ( !st.hasMoreTokens() ){
					st = new StringTokenizer( gi.readLine() );
				}
				fuel[j] = Integer.parseInt(st.nextToken());
			}
			for ( int j = 0; j < N; j++){
				if ( !st.hasMoreTokens() ){
					st = new StringTokenizer( gi.readLine() );
				}
				need[j] = Integer.parseInt(st.nextToken());
			}

			sum = 0;
			flag = true;
			for ( int j = 0; j < N; j++){
				sum += fuel[j] - need[j];
			}if ( sum < 0 ){
				go.println("Case "+(k+1)+": Not possible");
			}else{
				sum = 0;
				ans = 0;
				for ( int j = 0; j< N; j++  ){
					sum += fuel[j] - need[j];
					if ( flag && sum >= 0){
						ans = j+1;
						flag = false;
					}else if ( sum < 0 ){
						flag = true;
						sum = 0;
					}
				}
				go.println("Case "+(k+1)+": Possible from station "+ans);
			}
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
