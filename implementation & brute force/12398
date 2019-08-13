
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
		String l = gi.readLine().trim();
		char[] line;
		int[][] ans;
		int cur;
		int x,y;
		int caseN = 0;
		while ( l != null ){
			line = l.toCharArray();
			caseN++;
			ans = new int[3][3];
			for ( char c : line ){
				cur = c - 'a';
				x = cur/3; y = cur%3;
				ans[x][y]++;
				ans[x][y] %= 10;
				ans[max(0,x-1)][y] += (x==0?0:1);
				ans[max(0,x-1)][y] %= 10;
				ans[min(2,x+1)][y] += (x==2?0:1);
				ans[min(2,x+1)][y] %= 10;
				ans[x][max(0,y-1)] += (y==0?0:1);
				ans[x][max(0,y-1)] %= 10;
				ans[x][min(2,y+1)] += (y==2?0:1);
				ans[x][min(2,y+1)] %= 10;
			}
			go.println("Case #"+caseN+":");
			for ( int k = 0; k < 3; k++){
				for ( int j = 0; j < 2; j++){
					go.print(ans[k][j]+" ");
				}go.println(ans[k][2]);
			}
			l = gi.readLine();
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
