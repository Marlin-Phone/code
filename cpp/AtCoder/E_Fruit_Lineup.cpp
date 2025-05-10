// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MOD 998244353
#define int long long

// const int N =
int a, b, c, d;
int s = 0;

int getn1(int n) {
    int T = 1;
    for (int i = 1; i <= n; i++) {
        T = (T * i) % MOD;
    }
    return T;
}
int C(int n1, int n2) { return getn1(n1 + n2) / getn1(n2); }
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d;
    s = C(a, b) + C

        return 0;
}