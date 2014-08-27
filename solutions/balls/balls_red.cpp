#include <cstdio>
#include <iostream>


#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
using namespace std;

const int MAXN = 5000 + 10;
int n, k, x, a[MAXN], cur[MAXN], next1[MAXN];

void insert(int pos) {
    int now = 0;
    FOR(i,1,n) {
        if (i == pos) cur[++now] = x;
        cur[++now] = a[i];
    }
}

int destroy() {
    int nCur = n + 1, nNext;
    while (true) {
        bool updated = false;

        nNext = 0;
        int u = 1;
        while (u <= nCur) {
            int v = u;
            while (v < nCur && cur[v+1] == cur[v]) ++v;

            int len = v - u + 1;
            if (len < 3) {
                while (len--) next1[++nNext] = cur[v];
            }
            else {
                updated = true;
            }

            u = v + 1;
        }

        if (!updated) break;

        nCur = nNext;
        FOR(i,1,nCur) cur[i] = next1[i];
    }
    return nCur;
}

int main() {
    ios :: sync_with_stdio(false);
    while (cin >> n >> k >> x) {
		if (n == 0 and k == 0 and x == 0) break;
        FOR(i,1,n) cin >> a[i];

        int res = 0;
        FOR(i,1,n) {
            insert(i);
            res = max(res, max(n - destroy(), 0));
        }
        cout << res << endl;
    }
    return 0;
}