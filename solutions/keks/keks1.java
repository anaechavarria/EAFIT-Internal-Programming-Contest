import java.util.*;

public class keks1{
	
	public static final int MAXN = 500005;
	
	public static String s;
	public static boolean erased[] = new boolean[MAXN];
	public static int d[] = new int[MAXN];
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			
			int n = input.nextInt();
			int k = input.nextInt();
			if (n == 0 && k == 0) break;
			
			s = input.nextLine();
			s = input.nextLine();
			
			for (int i = 0; i < n; ++i) d[i] = s.charAt(i) - '0';

			for (int i = 0; i < n; ++i) erased[i] = false;

			solve(n, k);

			for (int i = 0; i < n; ++i){
				if (!erased[i]) System.out.print(s.charAt(i));
			}
			System.out.println("");
		}
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
				// If several occurrences pick the first one
				int best_val = -1;
				for (int j = i; j <= i + deletions; ++j){
					if (best_val == 9) break;
					if (d[j] > best_val){
						best_val = d[j];
						best_j = j;
					}
				}
			}
			for (int j = i; j < best_j; ++j) erased[j] = true;

			deletions -= best_j - i;
			i = best_j + 1;
		}
	}
	
}