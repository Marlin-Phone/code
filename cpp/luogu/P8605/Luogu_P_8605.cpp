// https://luogu.com.cn/problem/P8605
// 度数 数学
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
#define int long long

const int N = 1e5 + 10;
int T = 1;
int n, m;
// vector<int> g[N];
int d[N];       // 度数
int u[N], v[N]; // 存储边
int ans = 0;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        d[u[i]]++; // 度数++
        d[v[i]]++; // 度数++
    }

    for (int i = 0; i < m; i++) {
        if (d[v[i]] > 1 && d[u[i]] > 1) {
            ans += ((d[u[i]] - 1) * (d[v[i]] - 1)) * 2;
        }
    }
    cout << ans;
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