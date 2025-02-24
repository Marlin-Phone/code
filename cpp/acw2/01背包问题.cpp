#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;       // n个物品,背包容量
int v[N], w[N]; // 体积,价值
int mem[N][N];
int dp[N][N];

int dfs(int x, int spV) { // x当前物品, spV剩余体积
    if (mem[x][spV])
        return mem[x][spV];
    if (x > n) {
        mem[x][spV] = 0;
    } else if (spV < v[x]) {
        mem[x][spV] = dfs(x + 1, spV);
    } else if (spV >= v[x]) {
        mem[x][spV] = max(dfs(x + 1, spV), dfs(x + 1, spV - v[x]) + w[x]);
    }
    return mem[x][spV];
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    // int res = dfs(1, m);

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            if (j < v[i]) { //
                dp[i][j] = dp[i + 1][j];
            } else if (j >= v[i]) {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[1][m];

    // cout << res << endl;

    return 0;
}