// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n;
stack<int> stk;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    if (n % 2 == 0) {
        for (int i = n; i >= 2; i -= 2) {
            cout << i << " ";
        }
    } else {
        for (int i = n - 1; i >= 2; i -= 2) {
            cout << i << " ";
        }
    }
    cout << endl;
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