import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class keks2{
	
	public static final int MAXN = 500005;
	
	public static String s;
	public static boolean erased[] = new boolean[MAXN];
	public static List<List<Integer>> digit_pos = new ArrayList<List<Integer>>();
	public static int next_pos[] = new int [10];
	
	public static int d[] = new int[MAXN];
	
	public static void main(String[] args) throws Throwable{
		for (int i = 0; i < 10; ++i){
			digit_pos.add(new ArrayList<Integer>());
		}
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line = null;
		while((line = reader.readLine()) != null){
			String[] parts = line.split(" ");
			
			int n = Integer.parseInt(parts[0]);
			int k = Integer.parseInt(parts[1]);
			if (n == 0 && k == 0) break;
			
			s = reader.readLine();
			
			for (int i = 0; i < 10; ++i) digit_pos.get(i).clear();
			
			for (int i = 0; i < n; ++i){
				int d = s.charAt(i) - '0';
				digit_pos.get(d).add(i);
				erased[i] = false;
				if (i < 10) next_pos[i] = 0;
			}

			solve(n, k);

			for (int i = 0; i < n; ++i){
				if (!erased[i]) System.out.print(s.charAt(i));
			}
			System.out.println("");
		}
		reader.close();
	}
	
	public static void solve(int n, int k){
		int i = 0;
		int deletions = k;
		while (deletions > 0){
			int numbers_left = n - i;

			int best_j = -1;
			// Cannot delete any more numbers
			if (numbers_left == deletions){
				best_j = n;
			}else{
				// Pick biggest digit in positions [i ... i + deletions]
				for (int d = 9; d >= 0; --d){
					// No more occurrences of the chosen digit
					while (next_pos[d] < digit_pos.get(d).size() && digit_pos.get(d).get(next_pos[d]) < i) next_pos[d]++;;

					// The position of the next occurrence of the chosen digit
					int next_occurrence = next_pos[d] < digit_pos.get(d).size() ? digit_pos.get(d).get(next_pos[d]) : n;
					//printf("Next occurrence of %d is %d\n", d, next_occurrence);
					assert(next_occurrence >= i);
					if (next_occurrence <= i + deletions){
						best_j = next_occurrence;
						break;
					}
				}
			}
			for (int j = i; j < best_j; ++j) erased[j] = true;

			deletions -= best_j - i;
			i = best_j + 1;
		}
	}
	
}