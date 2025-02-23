#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T;
int l, r, k, x; // 非负整数
int n;          // (l <= n <= r)
int sum = 0;
int ans = 0;
int memo[N] = {0, 1};
int dp[N] = {0, 1};
int dp1, dp2, dp0;

int dfs(int x) {
    if (memo[x])
        return memo[x];
    if (x == k)
        return memo[k];
    return memo[x] = x ^ dfs(x - 1);
}
int main() {
    cin >> T;
    for (int j = 0; j < T; j++) {
        int flag = 0;
        cin >> l >> r >> k >> x;
        for (int i = k; i <= r; i++) {
            int temp = dfs(i); // 按位异或和
            cout << temp << " ";
            if (temp == x && l <= i && i <= r) {
                flag = 1;
                cout << i << endl;
                break;
            }
        }
        if (flag = 0)
            cout << -1 << endl;
    }

    // cin >> n;
    // int dp0 = 0, dp1 = 1;
    // for (int i = 2; i <= n; i++) {
    //     dp[i] = i ^ dp[i - 1];
    //     dp2 = i ^ dp1;
    //     dp1 = dp2;
    // }
    // cout << dp2 << endl;
    // cout << dp[n] << endl;
    // int ans = dfs(n);
    // cout << ans << endl;

    return 0;
}
// 10*9*8...*1