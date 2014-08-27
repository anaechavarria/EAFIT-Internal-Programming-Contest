import java.util.*;

public class clock{
	
	public static final int MIN_IN_DAY = 24 * 60;
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			
			int h = input.nextInt();
			int m = input.nextInt();
			
			if (h == -1 && m == -1) break;
			
			int old_time_in_min = h * 60 + m;
			int new_time_in_min = ( old_time_in_min - 45 + MIN_IN_DAY ) % MIN_IN_DAY;

			System.out.println(new_time_in_min / 60 +  " " + new_time_in_min % 60);
		}
	}
}