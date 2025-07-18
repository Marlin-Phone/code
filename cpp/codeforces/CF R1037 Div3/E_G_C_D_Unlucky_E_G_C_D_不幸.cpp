// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

const int N = 1e5 + 10;
int T = 1;
int n;
int p[N], s[N];
int a[N];

int __lcm(int a, int b) { return a * b / __gcd(a, b); }

bool check() {
    for (int i = 1; i <= n; i++) {
        a[i] = __lcm(p[i], s[i]);
    }
    int x = a[1];
    for (int i = 1; i <= n; i++) {
        x = __gcd(x, a[i]);
        if (x != p[i]) {
            return false;
        }
    }
    x = a[n];
    for (int i = n; i >= 1; i--) {
        x = __gcd(x, a[i]);
        if (x != s[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    if (check()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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