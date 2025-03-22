#include <bits/stdc++.h>
using namespace std;
#define MOD 100000

const int N = 1e5;
int n;
int mem[N];
int dp[N];

int fibo(int n) {
    if (mem[n]) {
        return mem[n];
    }
    if (n == 1 || n == 2) {
        return mem[n] = 1;
    }

    mem[n] = (fibo(n - 1) + fibo(n - 2)) % MOD;

    return mem[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << "dp[n] = " << dp[n] << endl;

    cout << "fibo(n) = " << fibo(n) << endl;

    return 0;
}