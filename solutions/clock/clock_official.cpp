#include <cstdio>
#include <cstdlib>

int main(int argc, char **argv, char **env) {
	int s, m;
	while (scanf("%d %d", &s, &m) == 2){
		if (s == -1 and m == -1) break;
		if ( m < 45 ){
			if ( s > 0 )
				s--;
			else
				s = 23;
			m = 60 - (45 - m);
		}
		else
			m -= 45;
		printf("%d %d\n", s, m);
	}
	return EXIT_SUCCESS;
}
