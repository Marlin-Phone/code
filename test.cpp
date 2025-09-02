#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
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

// const db eps = 1e-8;
const int MOD = 10007;
// const int N = 1e6 + 10;

int n, k;
int fast_pow(int x, int n) {
    int r = 1;
    while (n != 0) {
        if ((n & 1) == 1) {
            r = mod(r * x);
        }
        x = mod(x * x);
        n /= 2;
    }
    return r;
}

void solve() {
    cin >> n >> k;
    // for (int i = 1; i <= n; i++) {
    //     cout << fast_pow(k, i) << endl;
    // }
    cout << fast_pow(13, 100000000) << endl;
}

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