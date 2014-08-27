// Complexity O(n^2)
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
int d[MAXN];


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

int main(){
	ios::sync_with_stdio(false);
	int n, k;
    while (cin >> n >> k){
	
		if (n == 0 and k == 0) break;
		cin >> s;
		
		for (int i = 0; i < n; ++i) d[i] = s[i] - '0';
		
		memset(erased, false, sizeof erased);
		
		solve(n, k);
		
		for (int i = 0; i < n; ++i){
			if (!erased[i]) cout << s[i];
		}
		cout << endl;
		
    }
    return 0;
}
