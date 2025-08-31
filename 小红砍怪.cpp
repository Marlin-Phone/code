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
// const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n;
int arr[N];
map<int, pair<int, int>> mp;

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> arr[i];
        if (mp.count(arr[i]) == 0) {
            mp[arr[i]].first = i;
            mp[arr[i]].second = i;
        } else {
            mp[arr[i]].second = i;
        }
    }
    int maxnum = 0;
    for (auto it : mp) {
        int idx = it.first;
        auto [bg, ed] = it.second;
        maxnum = max(maxnum, ed - bg + 1);
    }
    cout << maxnum << endl;
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