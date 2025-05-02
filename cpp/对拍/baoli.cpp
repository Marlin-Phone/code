// https://luogu.com.cn/problem/P
// 前缀和 枚举
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 1e3 + 10;
int n;
int a[N];
int s[N];
int res = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int l1 = 1; l1 < n; l1++) {
        for (int r1 = l1; r1 < n; r1++) {
            for (int l2 = r1 + 1; l2 <= n; l2++) {
                for (int r2 = l2; r2 <= n; r2++) {
                    res =
                        min(res, abs(s[r1] - s[l1 - 1] - (s[r2] - s[l2 - 1])));
                }
            }
        }
    }

    cout << res;

    return 0;
}