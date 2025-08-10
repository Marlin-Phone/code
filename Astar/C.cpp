#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define db double
#define float db
#define vi vector<int>
#define pii pair<int, int>
#define pdd pair<db, db>
// Aliases
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define endl '\n'
// Iterating
#define F(i, m) for (int i = 1; i <= m; i++)
#define fi(m) F(i, m)
#define fj(m) F(j, m)
#define fk(m) F(k, m)
#define ALL(x) x.begin(), x.end()
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

const int N = 5e5 + 10;
// const int MOD = 1e9 + 7;
// const db eps = 1e-8;

int n, k;
int s[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}