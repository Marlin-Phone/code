// https://luogu.com.cn/problem/P1115
// 前缀和 | dp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 2e5 + 10;
int n;
int a[N], b[N];
int s[N];
int ans = -LONG_LONG_MAX;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) {
            b[i] = a[i];
        } else {
            b[i] = max(a[i], b[i - 1] + a[i]);
        }
        ans = max(ans, b[i]);
    }
    cout << ans;

    return 0;
}