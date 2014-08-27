// Slow solution O(n^3)
#include <iostream>
#include <cassert>
#include <cstdio>
using namespace std;

#define D(x) cout << #x " = " << x << endl

const int MAXN = 5005;

int n, k, x;
int c[MAXN], b[MAXN];

// See how many balls are deleted when placing the new ball between c[pos-1] and c[pos]
int try_pos(int pos){
	// Build the array of all the balls plus the inserted balls
	for (int i = 0; i < n; ++i){
		if (i < pos) b[i] = c[i];
		if (i >= pos) b[i+1] = c[i];
	}
	b[pos] = x;
	
	int balls_left = n+1;
	bool changed;
	do{
		changed = false;
		// Find the first ball whose next two balls are of the same color
		int left_delete_index = -1, right_delete_index = -1;
		for (int i = 0; i+2 < balls_left; ++i){
			if(b[i] == b[i+1] and b[i] == b[i+2]){
				left_delete_index = right_delete_index = i;
				// Find the first ball that is not going to be deleted
				while(b[right_delete_index] == b[left_delete_index]) right_delete_index++;
				break;
			}
		}
		
		// Delete the balls b[left_delete_index ... right_delete_index) from the b array
		if (left_delete_index != -1){
			changed = true;
			for (int i = 0; i + right_delete_index < balls_left; ++i){
				b[i + left_delete_index] = b[i + right_delete_index]; 
			}
			balls_left -= right_delete_index - left_delete_index;
		}
	}while(changed);
	
	if (balls_left == n+1) return 0;
	
	return n - balls_left;
}

int main() {
	while(cin >> n >> k >> x){
		if (n == 0 and k == 0 and x == 0) break;
		for (int i = 0; i < n; ++i) cin >> c[i];
		
		int best = 0;
		for (int pos = 0; pos <= n; ++pos){
			best = max(best, try_pos(pos));
		}
		cout << best << endl;
	}
	
	return 0;
}