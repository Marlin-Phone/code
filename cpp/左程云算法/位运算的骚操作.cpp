// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;

void solve() {
    int n;
    cin >> n;
    debug(__builtin_popcount(n)); // 直接返回n的二进制1的个数
    debug(__builtin_clz(n));    // 计算前导0的个数(返回n的二进制最高位的1的位置)
    debug(__builtin_ctz(n));    // 计算末尾0的个数(返回n的二进制最低位的0的位置)
    debug(__builtin_parity(n)); // 计算n的奇偶性(返回n的二进制中1的个数的奇偶性)
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}