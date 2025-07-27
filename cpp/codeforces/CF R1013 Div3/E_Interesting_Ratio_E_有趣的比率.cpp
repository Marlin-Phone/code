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

int __lcm(int a, int b) { return a * b / __gcd(a, b); }
int f(int a, int b) { return __lcm(a, b) / __gcd(a, b); }

void solve() { cin >> n; }

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