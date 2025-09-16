#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",
// "fast-math")
using namespace std;

// Types
// #define ll long long
// #define int ll
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
const int N = 2e6 + 10;
int ans[N];

int n, k;
void dfs(int l, int r, int rem) {
    if (rem == 0) {
        return;
    }
    if (l == r) {
        ans[l]++;
        return;
    }
    int mid = (l + r) >> 1;
    dfs(l, mid, rem / 2);
    dfs(mid + 1, r, rem - (rem / 2));
}
void solve() {
    cin >> n >> k;
    int m = (1 << n);
    for (int i = 1; i <= m; i++) {
        ans[i] = k / m;
    }
    if (k % m) {
        cout << 1 << endl;
        dfs(0, m - 1, k % m);
    } else {
        cout << 0 << endl;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
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