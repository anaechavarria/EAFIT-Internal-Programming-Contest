// Complexity O(n)
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXN = 500005;

string s;
bool erased[MAXN];
int next_pos[10];
vector<int> digit_pos[10];

void solve(int n, int k){
	int i = 0;
	int deletions = k;
	while (deletions > 0){
		int numbers_left = n - i;
		assert(numbers_left >= deletions);
		
		int best_j;
		// Cannot delete any more numbers
		if (numbers_left == deletions){
			best_j = n;
		}else{
			// Pick biggest digit in positions [i ... i + deletions]
			for (int d = 9; d >= 0; --d){
				// No more occurrences of the chosen digit
				while (next_pos[d] < digit_pos[d].size() and digit_pos[d][next_pos[d]] < i) next_pos[d]++;;
			
				// The position of the next occurrence of the chosen digit
				int next_occurrence = next_pos[d] < digit_pos[d].size() ? digit_pos[d][next_pos[d]] : n;
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

int main(){
	//ios::sync_with_stdio(false);
	int n, k;
    while (cin >> n >> k){
	
		if (n == 0 and k == 0) break;
		cin >> s;
		
		for (int i = 0; i < 10; ++i) digit_pos[i].clear();
		
		for (int i = 0; i < n; ++i){
			int d = s[i] - '0';
			digit_pos[d].push_back(i);
		}
		
		memset(erased, false, sizeof erased);
		memset(next_pos, 0, sizeof next_pos);
		
		solve(n, k);
		
		for (int i = 0; i < n; ++i){
			if (!erased[i]) cout << s[i];
		}
		cout << endl;
		
    }
    return 0;
}
