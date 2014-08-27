#include <iostream>
using namespace std;

const int MIN_IN_DAY = 24 * 60;

int main(){
	int h, m;
	while (cin >> h >> m){
		if (h == -1 and m == -1) break;
		
		int old_time_in_min = h * 60 + m;
		int new_time_in_min = ( old_time_in_min - 45 + MIN_IN_DAY ) % MIN_IN_DAY;
		
		cout << new_time_in_min / 60 <<  " " << new_time_in_min % 60 << endl;
	}
	
	return 0;
}
