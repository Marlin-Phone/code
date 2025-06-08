// https://luogu.com.cn/problem/P3916
// DFS 反向建图
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1e5 + 10;
int T = 1;
int n, m;
vector<int> g[N];
int ans[N];

void dfs(int u, int max_v) {
    if (ans[u]) {
        return;
    }
    ans[u] = max_v;
    for (int v : g[u]) {
        dfs(v, max_v);
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        g[vv].push_back(uu);
    }
    for (int i = n; i >= 1; i--) {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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