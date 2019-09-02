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
		String s = gi.readLine().trim();
		while (s != null) {
			List<Integer> l = new ArrayList<>();
			String[] arr;
			do {
				arr = s.trim().split(" ");
				for (String e : arr) {
					l.add(Integer.parseInt(e));
				}
				s = gi.readLine();
			}while (!arr[arr.length - 1].equals("-999999"));
			l.remove(l.size() - 1);
			BigInteger prod = BigInteger.ONE;
			int last = -1;
			BigInteger ans = new BigInteger("-111111111");
			int n = l.size();
			BigInteger lastValue = BigInteger.ONE;
			for ( int k = 0; k < n; k++ ){
				prod = prod.multiply(new BigInteger("" + l.get(k)));
				if (prod.compareTo(BigInteger.ZERO) < 0){
					if (last != -1) {
						BigInteger temp = prod.divide(lastValue);
						if (ans.compareTo(temp) < 0) {
							ans = temp;
						}
					}
				}
				if (ans.compareTo(prod) < 0) {
					ans = prod;
				}
				if (l.get(k) < 0 && last == -1){
					last = k;
					lastValue = prod;
				}
				if (l.get(k) == 0) { prod = BigInteger.ONE; last = -1; lastValue = BigInteger.ONE; }
			}
			go.println(ans);
		}
		go.close();
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


