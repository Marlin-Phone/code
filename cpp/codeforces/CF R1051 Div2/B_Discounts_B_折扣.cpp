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

int n, k;
int cost[N];
int fre[N];

void solve() {
    int ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> fre[i];
    }
    sort(cost + 1, cost + 1 + n);
    sort(fre + 1, fre + 1 + k);

    // for (int i = 1; i <= n; i++) {
    //     cout << cost[i] << " ";
    // }
    // cout << endl;

    // for (int i = 1; i <= k; i++) {
    //     cout << fre[i] << " ";
    // }
    // cout << endl;
    // cout << endl;

    int idx = n;
    for (int i = 1; i <= k; i++) {
        int temp = fre[i];
        // dbg(temp);
        if (idx < fre[i]) {
            break;
        }
        while (temp) {
            // dbg(temp);
            if (temp != 1) {
                // dbg(cost[idx]);
                ans += cost[idx];
            }
            idx--;
            temp--;
        }
    }
    while (idx >= 1) {
        // dbg(idx);
        // dbg(cost[idx]);
        ans += cost[idx--];
    }
    cout << ans << endl;
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