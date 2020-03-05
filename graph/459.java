/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import static java.lang.Math.*;
import java.math.*;

public class Main{

	static PrintWriter go = new PrintWriter(System.out);

	public static void main(String args[]) throws IOException,FileNotFoundException {
		BufferedReader gi = new BufferedReader(new InputStreamReader(System.in, "ISO-8859-1"));
		int t = Integer.parseInt(gi.readLine());
		String s = gi.readLine();
		for ( int k = 0; k < t; k++ ){
			Map<Character, Set<Character>> g = new HashMap<>();
			Set<Character> vis = new HashSet<Character>();
			s = gi.readLine();
			char sz = s.charAt(0);
			for ( char j = 'A'; j <= sz; j++ )
				g.put(j, new HashSet<>());
			s = gi.readLine();
			while (s != null && !s.equals("")) {
				g.get(s.charAt(0)).add(s.charAt(1));
				g.get(s.charAt(1)).add(s.charAt(0));
				s = gi.readLine();
			}
			int ans = 0;
			for ( char j = 'A'; j <= sz; j++ )
				ans += dfs(g, j, vis);
			go.println(ans);
			if (k < t - 1)
				go.println();
		}
		go.close();
	}

	static int dfs(Map<Character, Set<Character>> g, char v, Set<Character> vis) {
		if (vis.contains(v))
			return 0;
		vis.add(v);
		for (Character adj : g.get(v)) 
			dfs(g, adj, vis);
		return 1;
	}

	static int[] parseArray(BufferedReader gi) throws IOException{
		String[] line = gi.readLine().split(" ");
		int[] rez = new int[line.length];
		for ( int k = 0; k < line.length; k++){
			rez[k] =  Integer.parseInt(line[k]);
		}
		return rez;
	}

}
