// https://luogu.com.cn/problem/P8649
// 前缀和 前缀和余数的性质 枚举 组合公式C(n, k) = n! / (k! * (n - 1))
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 1e5 + 10;
int n, k;
int a[N];
int Sa[N];
int cnt[N];
int C[N];
int first[N];
int last[N];
int ans = 0;

// int n1(int x) {
//     int res = 1;
//     for (int i = 1; i <= x; i++) {
//         res *= i;
//     }
//     return res;
// }
void getC(int x) { // C(n, 2);
    ans += x * (x - 1) / 2;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Sa[i] = (Sa[i - 1] + a[i]) % k;
    }

    for (int i = 0; i <= n; i++) {
        cnt[Sa[i]]++;
    }

    // first[0] = 0;
    for (int i = 0; i < k; i++) {
        // ans += cnt[i] * (cnt[i] - 1);
        getC(cnt[i]);
    }
    cout << ans;

    return 0;
}