// https://www.luogu.com.cn/problem/P3817
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int n, x;
int a[N];
int ans = 0;

signed main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > x) {
            ans += a[i] - x;
            a[i] = x;
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        while (a[i] + a[i + 1] > x) {
            ans += a[i] + a[i + 1] - x;
            a[i + 1] -= a[i] + a[i + 1] - x;
        }
    }

    cout << ans;

    return 0;
}