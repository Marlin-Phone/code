#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244853;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n), p(n);
    for (int &x : a)
        scanf("%d", &x);
    for (int &x : p)
        scanf("%d", &x);

    vector<long long> dp(m);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        vector<long long> new_dp(m);
        int ai = a[i] % m;
        int pi = p[i];
        int qi = (1 - pi + MOD) % MOD;

        for (int j = 0; j < m; ++j) {
            if (!dp[j])
                continue;
            int k = (j + ai) % m;
            new_dp[k] = (new_dp[k] + dp[j] * pi) % MOD;
            new_dp[j] = (new_dp[j] + dp[j] * qi) % MOD;
        }
        dp = move(new_dp);
    }
    printf("%lld\n", dp[0] % MOD);
    return 0;
}
