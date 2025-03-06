// https://www.luogu.com.cn/problem/P1216
// dfs --> 记忆化搜索 --> 逆序递推 --> 正序递推 --> 二维变一维
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n;
int g[N][N];
int ans = 0;
int mem[N][N];
int dp[N];

int dfs(int x, int y) {
    if (mem[x][y])
        return mem[x][y];
    if (x > n || y > n)
        return 0;
    mem[x][y] = max(dfs(x + 1, y), dfs(x + 1, y + 1)) + g[x][y];
    return mem[x][y];
}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            dp[j] = max(dp[j], dp[j + 1]) + g[i][j];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + g[i][j];
    //     }
    // }

    // for (int i = 1; i <= n; i++) {
    //     cout << dp[n][i] << " ";
    //     ans = max(ans, dp[n][i]);
    // }

    // cout << ans << endl;
    cout << dp[1] << endl;
    // cout << dfs(1, 1);

    return 0;
}