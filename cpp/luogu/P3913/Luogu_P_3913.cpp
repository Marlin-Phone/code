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
const int N = 1e6 + 10;

int n, m;
// vector<pair<int, int>> point(N);
// pair<int, int> point;
unordered_set<int> x;
unordered_set<int> y;

void solve() {
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int p_x, p_y;
        cin >> p_x >> p_y;
        if (x.count(p_x) && y.count(p_y)) {
            continue;
        } else if (x.count(p_x) && !y.count(p_y)) {
            // ans += n - x.size();
            // dbg(ans);
            ans += n - x.size();
            // dbg(ans);
            // ans -= x.size() * y.size();
        } else if (!x.count(p_x) && y.count(p_y)) {
            // dbg(ans);
            ans += n - y.size();
            // dbg(ans);
            // ans += n - y.size();
            // ans -= x.size() * y.size();
        } else {
            // cout << "Here" << endl;
            // dbg(ans);
            ans += n - x.size();
            ans += n - y.size();
            ans -= 1;
            // dbg(ans);
        }
        x.insert(p_x);
        y.insert(p_y);
    }
    cout << ans << endl;
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