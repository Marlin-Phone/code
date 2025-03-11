#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[5010];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;

    return 0;
}