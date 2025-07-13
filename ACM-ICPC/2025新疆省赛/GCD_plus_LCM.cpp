// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long
#define MOD 1000000009;

// const int N =
int T = 1;
int a, b, n;

int __lcm(int a, int b) { return a * b / __gcd(a, b); }
int f(int x) { return __lcm(x, b) + __gcd(x, b); }
int dfs(int n) {
    if (n == 1) {
        return f(a);
    }
    dfs(n - 1);
}
void solve() {
    cin >> a >> b >> n;
    cout << f(a) << endl;
    cout << f(f(a)) << endl;
    cout << f(f(f(a))) << endl;
    cout << f(f(f(a))) << endl;
    dfs(n);
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