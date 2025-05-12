// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// const int N =
int T;
int n, m, p, q; // 数组长度 元素总和 段长度 段的和

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        int temp = n % p;
        if (temp == 0) {
            // 当 n 是 p 的整数倍时，总和必须等于 (n/p) * q
            long long k = 1LL * n / p;
            if (1LL * k * q == m) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            // 当 n 不是 p 的整数倍时，总可以调整余数部分的值，满足任意 m
            cout << "YES" << endl;
        }
    }

    return 0;
}