#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const double eps = 1e-8;
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int x, n, p;
int MOD;

int ksm(int x, int n) {
    int ans = 1;
    while (n > 0) {
        if (n % 2) {
            ans = mod(ans * x);
        }
        x = mod(x * x);
        n /= 2;
    }

    return ans;
}

void solve() {
    cin >> x >> n >> p;
    MOD = p;
    cout << x << '^' << n << " mod " << p << "=" << mod(ksm(x, n)) << endl;
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