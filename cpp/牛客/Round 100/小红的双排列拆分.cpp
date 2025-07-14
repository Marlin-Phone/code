// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e4;
int T = 1;
int n;
vector<int> vec(N, 0);

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> vec[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    for (int i = n + 1; i <= 2 * n; i++) {
        cout << vec[i] << " ";
    }
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