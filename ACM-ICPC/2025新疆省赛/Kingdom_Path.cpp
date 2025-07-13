// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long
#define MOD 1000000007;

const int N = 2e5 + 10;
int T = 1;
int n;
int a[N];

int f(int num) {
    int cnt1 = 0;
    int cnt0 = 0;
    while (num > 0) {
        int temp = num % 2;
        if (temp == 1) {
            cnt1++;
        } else {
            cnt0++;
        }
        num /= 2;
    }
    return cnt1;
}
// int __and(int a, int b) { return a & b; }
int dfs(int now, int x) {
    if (now + 1 == x) {
        return f(a[now] & a[x]) % MOD;
    }

    return (dfs(now, x - 1) * f(a[x - 1] & a[x])) + (f(a[now] & a[x]));
}

int dp[N];

void solve() {
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = 1;
    // for (int i = 1; i <= n; i++){
    //     dp[i] = sum(dp)
    // }
    // sum += f((a[1] & a[n - 1]) * (a[n - 1] & a[n])) + f(a[1] & a[n]);
    // sum +=
    // sum += f(a[1] & a[n])

    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // cout << dfs(1, n) << endl;

    cout << sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}