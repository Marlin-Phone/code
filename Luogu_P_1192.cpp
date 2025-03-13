// https://www.luogu.com.cn/problem/P1192
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int dp[N];

int main() {
    cin >> n >> k;

    dp[0] = 1;
    dp[1] = 1;
    // dp[2] = 2;
    // dp[3] = 4;
    // dp[4] = 8;
    // // for (int i = 2; i <= k; i++) { // 初始化
    //     dp[i] = dp[i - 1] + 1;
    // }

    // for (int i = 1; i <= k; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    for (int i = 2; i <= n; i++) {
        for (int j = i, cnt = 0; cnt < k && j - 1 >= 0; j--, cnt++) {
            dp[i] += dp[j - 1];
            dp[i] %= 100003;
        }
    }

    // for (int i = 3; i <= n; i++) {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }

    // for (int i = 0; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n];

    return 0;
}