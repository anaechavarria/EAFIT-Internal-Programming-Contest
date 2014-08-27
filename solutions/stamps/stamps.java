import java.util.*;

public class stamps{

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			
			int x = input.nextInt();
			int y = input.nextInt();
			
			if (x == 0 && y == 0) break;
			
			System.out.println(x + y);
		}
	}
}