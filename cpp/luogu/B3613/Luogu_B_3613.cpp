// https://luogu.com.cn/problem/P3613
// 图的建立与遍历
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 5e5 + 10;
int T = 1;
int n, m;

void solve() {
    cin >> n >> m;
    vector<int> g[n + 10];

    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        g[uu].push_back(vv);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
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