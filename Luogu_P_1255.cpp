// 需要高精度优化
// https://www.luogu.com.cn/
#include <iostream>
using namespace std;

const int N = 5010;
int n;
long long dp[N];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}