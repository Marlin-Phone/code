// https://luogu.com.cn/problem/P8783
// 前缀和
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 510;
int n, m, k;
int a[N][N];
int S1[N][N], S[N][N];
int ans = 0;
int cnt1 = 0;
int times = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            S1[i][j] = S1[i][j - 1] + a[i][j];
            // cout << S1[i][j] << " ";
        }
        // cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            S[i][j] = S[i - 1][j] + S1[i][j];
        }
    }

    for (int xb = 1; xb <= n; xb++) {
        for (int yb = 1; yb <= m; yb++) {
            for (int xe = xb; xe <= n; xe++) {
                for (int ye = yb; ye <= m; ye++) {
                    int temp = S[xe][ye] - S[xe][yb - 1] - S[xb - 1][ye] +
                               S[xb - 1][yb - 1];
                    if (temp <= k) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}