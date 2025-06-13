// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
#define int long long

const int N = 1010;
int T = 1;
int n, m, k;
int g[N][N];
int g0[N][N];
int ans[N * N];
int idx = 1;

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> g0[i][j];
        }
    }
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            // for (int i0 = 1 + i; i0 <= k + i; i0++){
            //     for (int j0 = 1 + j; j0 <= k + j; j0++){
            //         ans[idx] =
            //     }
            // }
            for (int i0 = 1; i0 <= k; i0++) {
                for (int j0 = 1; j0 <= k; j0++) {
                    ans[idx] += g[i0 + i][j0 + j] * g0[i0][j0];
                }
            }
            idx++;
        }
    }
    for (int i = 1; i <= (n - k + 1) * (m - k + 1); i++) {
        cout << ans[i] << " ";
        if (i % (m - k + 1) == 0) {
            cout << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}