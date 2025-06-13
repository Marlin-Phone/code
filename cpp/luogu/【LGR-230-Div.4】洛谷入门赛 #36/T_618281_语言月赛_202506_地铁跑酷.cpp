// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
#define int long long

const int N = 1e5 + 10;
int T = 1;
int n, k, s, t;
int tim[N];
int b[N];
int c[N];
int sum = 0;

void solve() {
    cin >> n; // 车站总数
    for (int i = 1; i < n; i++) {
        cin >> tim[i]; // i->i+1的行车时间
    }
    cin >> k; // 停靠站数量
    for (int i = 1; i <= k; i++) {
        cin >> b[i]; // 停靠的车站编号
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i]; // 这些站的停靠时间
    }
    cin >> s >> t; // s上车,t下车

    for (int i = s; i < t; i++) {
        sum += tim[i];
    }
    for (int i = 1; i <= k; i++) {
        if (s < b[i] && b[i] < t) {
            sum += c[i];
        }
    }

    cout << sum;
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