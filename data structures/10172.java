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
		for ( int j = 0; j < T; j++ ){
			int n,s,q; int[] l = parseArray(gi);
			n = l[0]; s = l[1]; q = l[2];
			Stack<Integer> st = new Stack<>();
			Queue<Integer>[] qu = new Queue[n];
			int f = 0;
			for ( int k = 0; k < n; k++ ){ qu[k] = new LinkedList<>(); }
			for ( int k = 0; k < n; k++ ){
				l = parseArray(gi);
				f += l[0];
				for ( int i = 0; i < l[0]; i++ ){
					qu[k].add(l[i+1]);
				}
			}
			int pos = 0;
			long ans = -2;
			while (f > 0){
				while (!st.isEmpty() && qu[pos].size() <= q){
					if (st.peek() == pos + 1){ st.pop(); f--; }
					else if (qu[pos].size() < q){ qu[pos].add(st.pop()); }
					else { break; }
					ans++;
				}
				while (st.size() < s && !qu[pos].isEmpty()){ st.push(qu[pos].remove()); ans++; }
				pos++; pos %= n;
				ans += 2;
			}
			go.println(ans);
		}
		go.close();
	}

	static int[] parseArray(BufferedReader gi) throws IOException{
		String[] line = gi.readLine().split(" ");
		int[] rez = new int[line.length];
		for ( int k = 0; k < line.length; k++){
			rez[k] = Integer.parseInt(line[k]);
		}
		return rez;
	}

}
