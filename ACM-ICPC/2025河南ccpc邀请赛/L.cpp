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
#define vii vector<pii>
#define pdd pair<db, db>
#define vdd vector<pdd>
// Aliases
#define x first
#define y second
#define pb push_back
#define mp make_pair
// Iterating
#define F(i, m) for (int i = 1; i <= (m); i++)
#define fi(m) F(i, m)
#define fj(m) F(j, m)
#define fk(m) F(k, m)
#define ALL(x) x.begin(), x.end()
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && i(s0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) (((u) + (d) - 1) / (d))
#define psub(a, b) mp(a.x - b.x, a.y - b.y)
#define pow2(a) ((a) * (a))
// Others
#define endl '\n'
#define dbg(x)                                                                 \
    cout << "Dbg: " << #x << " = " << fixed << setprecision(8) << (x) << endl;

const int N = 44435556 + 10;
const int MOD = 1e9 + 7;
const int linf = 4e18;
const db dinf = 1e20;
const db pi = acos(-1.0);
const db eps = 1e-8;

void solve() {}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}