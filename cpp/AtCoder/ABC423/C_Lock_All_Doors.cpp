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

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n, r;
int L[N];
int left0 = -1, right0 = -1;
int ans = 0;

void solve() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= n; i++) {
        if (L[i] == 0) {
            left0 = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (L[i] == 0) {
            right0 = i;
            break;
        }
    }

    if (left0 != -1 && left0 <= r) {
        for (int i = r; i >= left0; i--) {
            if (L[i] == 1) {
                ans++;
            }
        }
        // dbg(ans);
        ans += r - left0 + 1;
        // dbg(ans);
    }
    if (right0 != -1 && r < right0) {
        int temp = 0;
        for (int i = r + 1; i < right0; i++) {
            if (L[i] == 1) {
                // dbg(i);
                temp++;
            }
        }
        // dbg(temp);
        ans += temp;
        // dbg(ans);
        ans += right0 - r;
        // dbg(ans);
    }
    // dbg(left0);
    // dbg(right0);
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