// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;

void solve() {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b > d) {
            // debug(b);
            // debug(d);
            // debug(ans);
            // debug(a);
            ans += min(a, c);
            // debug(ans);
        }
        int temp = max(a - c, 0ll) + max(b - d, 0ll);
        // debug(temp);
        ans += max(a - c, 0ll) + max(b - d, 0ll);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}