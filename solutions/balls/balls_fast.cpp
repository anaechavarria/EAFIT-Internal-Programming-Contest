// Faster solution O(n^2)
#include <iostream>
#include <cassert>
#include <cstdio>
using namespace std;

#define D(x) cout << #x " = " << x << endl

const int MAXN = 5005;
int c[MAXN];

// The position if the first ball of a different color than the one at position i if going left/right
int max_right[MAXN], max_left[MAXN];


// Fill the max_right and max_left arrays
void process(int n){
	int right, left, i;
	
	right = i = 0;
	while(i < n){
		while (right < n and c[i] == c[right]) right++;
		for(int j = i; j < right; ++j) max_right[j] = right;
		i = right;
	}
	
	left = i = n-1;
	while(i >= 0){
		while (left >= 0 and c[i] == c[left]) left--;
		for (int j = i; j > left; --j) max_left[j] = left;
		i = left;
	}
}

// See how many balls are deleted when inserting a ball of color x
// between c[pos] and c[pos+1]
int try_pos(int pos, int x, int n){
	int left = pos, right = pos+1;
	
	// If the left and right balls are of color x
	if (c[left] != x or c[right] != x) return 0;
	
	int right_block_size, left_block_size;
	do{
		left = max_left[left];
		right = max_right[right];
		
		right_block_size = max_right[right] - right;
		left_block_size = left - max_left[left];
		
		// Reached an edge so no more balls are deleted
		if (left < 0 or right >= n) break;
	}while( c[left] == c[right] and  right_block_size + left_block_size >= 3 );

	return right - left - 1;
}

int main() {
	int n, k, x;
	while(cin >> n >> k >> x){
		if (n == 0 and k == 0 and x == 0) break;
		
		// Add unique colors to the left and right of the array
		c[0] = k+1;
		for (int i = 1; i <= n; ++i) cin >> c[i];
		c[n+1] = k+2;
		
		process(n+2);
		
		int best = 0;
		for (int pos = 1; pos < n; ++pos){
			best = max(best, try_pos(pos, x, n+2));
		}
		
		cout << best << endl;
	}
	
	return 0;
}