// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;

int p[4] = {2, 3, 5, 7}; // 单位数质数
int n = 4;

void solve() {
    int l, r;
    cin >> l >> r;

    int tot = r - l + 1; // 区间总数
    int bad = 0;         // 被 2,3,5,7 至少一个整除的数的个数

    // 枚举 4 个质数的非空子集 (1 到 15)
    for (int i = 1; i < (1 << n); i++) {
        int m = 1;
        int c = 0; // 统计子集中元素个数（即二进制中 1 的个数）

        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                m *= p[j];
                c++;
            }
        }

        // 计算 [l, r] 中能被 m 整除的数的个数
        int cnt = r / m - (l - 1) / m;

        // 容斥原理：奇加偶减
        if (c % 2 == 1) {
            bad += cnt;
        } else {
            bad -= cnt;
        }
    }

    cout << tot - bad << endl;
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