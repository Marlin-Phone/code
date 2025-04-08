// https://luogu.com.cn/problem/B3693
// 二维前缀和 | unsigned long long | 异或和
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long

const int N = 1e3 + 10;
int T;
int n, m, q;
const int MOD = pow(2, 64);
int a[N][N];
int S1[N][N];
int S[N][N];
vector<int> ans;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                S1[i][j] = (S1[i][j - 1] + a[i][j]) % MOD;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                S[i][j] = (S[i - 1][j] + S1[i][j]) % MOD;
            }
        }

        int q0 = q;
        int ans = 0;
        while (q0--) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            int sum =
                (S[x][y] - S[u - 1][y] - S[x][v - 1] + S[u - 1][v - 1]) % MOD;
            ans ^= sum;
        }

        cout << ans << endl;
    }

    return 0;
}