#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype> 
#include <numeric> 
#include <iomanip>
#include <assert.h>
using namespace std;
#define sqr(_) ((_)*(_))

typedef pair<int, int> Pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long LL;

const int MAXN = 5000 + 10;

int n, k, x, a[MAXN], b[MAXN], Tohka;

void check(int p){
	if (a[p] != x || b[p] < 2)
		return ;
	int Mashiro = 2;
	for (int l = p - 1, r = p + 1; l >= 1 && r <= n && a[l] == a[r] && b[l] + b[r] >= 3; Mashiro += b[l] + b[r], --l, ++r);
	Tohka = max(Tohka, Mashiro);
}

int main(){
	while(cin >> n >> k >> x)
		if (n == 0 and k == 0 and x == 0) break;
		
		int N = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[++N];
			if (a[N] == a[N - 1])
				--N;
			++b[N];
		}
		n = N;
		for (int i = 1; i <= n; ++i)
			check(i);
		cout << Tohka << endl;
	}
	
	return 0;
}