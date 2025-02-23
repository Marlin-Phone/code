#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int memo[N];
int dp[N];

int dfs(int x) {
    if (memo[x]) {
        return memo[x];
    }
    if (x <= 2) {
        return x;
    }
    return memo[x] = dfs(x - 1) + dfs(x - 2);
}

int main() {
    int n;
    cin >> n;

    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}