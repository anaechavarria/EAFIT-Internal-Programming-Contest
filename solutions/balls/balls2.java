import java.util.*;

public class balls2{

	public static final int MAXN = 5005;
	public static int c[] = new int[MAXN];
	
	// The position if the first ball of a different color than the one at position i if going left/right
	public static int max_left[] = new int[MAXN];
	public static int max_right[] = new int[MAXN];

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			
			int n = input.nextInt();
			int k = input.nextInt();
			int x = input.nextInt();
			
			if (n == 0 && k == 0 && x == 0) break;
			
			c[0] = k+1;
			for (int i = 1; i <= n; ++i) c[i] = input.nextInt();
			c[n+1] = k+2;
			
			process(n+2);
			
			int best = 0;
			for (int pos = 1; pos < n; ++pos){
				best = Math.max(best, try_pos(pos, x, n+2));
			}
			System.out.println(best);
		}
	}
	
	// Fill the max_right and max_left arrays
	public static void process(int n){
		int right, left, i;

		right = i = 0;
		while(i < n){
			while (right < n && c[i] == c[right]) right++;
			for(int j = i; j < right; ++j) max_right[j] = right;
			i = right;
		}

		left = i = n-1;
		while(i >= 0){
			while (left >= 0 && c[i] == c[left]) left--;
			for (int j = i; j > left; --j) max_left[j] = left;
			i = left;
		}
	}
	
	// See how many balls are deleted when inserting a ball of color x
	// between c[pos] and c[pos+1]
	public static int try_pos(int pos, int x, int n){
		int left = pos, right = pos+1;

		// If the left and right balls are of color x
		if (c[left] != x || c[right] != x) return 0;

		int right_block_size, left_block_size;
		do{
			left = max_left[left];
			right = max_right[right];

			right_block_size = max_right[right] - right;
			left_block_size = left - max_left[left];

			// Reached an edge so no more balls are deleted
			if (left < 0 || right >= n) break;
		}while( c[left] == c[right] && right_block_size + left_block_size >= 3 );

		return right - left - 1;
	}
}