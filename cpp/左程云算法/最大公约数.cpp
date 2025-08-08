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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    // cin >> n;
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << __gcd(a, b) << endl;
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