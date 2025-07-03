// https://luogu.com.cn/problem/P1807
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1600;
int T = 1;
int n, m;
vector<int> topo;
vector<pair<int, int>> g[N];
vector<int> inDegree(N, 0);
queue<int> q;
int dp[N];

void topoSort() {
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            topo.push_back(i);
        }
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        int u = t;
        for (auto neighbor : g[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (--inDegree[v] == 0) {
                q.push(v);
                topo.push_back(v);
            }
        }
    }
}
void solve() {
    // memset(dp, 0xff, sizeof(dp))
    fill(dp, dp + N, -1e9);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        inDegree[v]++;
    }
    topoSort();
    dp[1] = 0;
    for (auto u : topo) {
        for (auto neighbor : g[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            dp[v] = max(dp[v], dp[u] + w);
        }
    }
    cout << (dp[n] == -1e9 ? -1 : dp[n]) << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << inDegree[i] << " ";
    // }
    // cout << endl;
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