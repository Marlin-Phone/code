// https://luogu.com.cn/problem/P3379
// 最近公共祖先 LCA 朴素法
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 5e5 + 10;
int T = 1;
int n, m, s;
vector<int> g[N];
queue<int> q;
int fa[N];
int dep[N];
int vis[N];

// 预处理O(n)
void bfs(int root) {
    q.push(root);
    vis[root] = true; // 记录当前节点已访问
    dep[root] = 0;    // 记录当前节点的深度
    fa[root] = -1;    // 记录当前节点的父节点
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (vis[v]) {
                continue;
            }
            vis[v] = true;
            dep[v] = dep[u] + 1;
            fa[v] = u;
            q.push(v);
        }
    }
}
// 查询O(m * h)
int lca(int a, int b) {
    while (dep[a] > dep[b]) {
        a = fa[a];
    }
    while (dep[b] > dep[a]) {
        b = fa[b];
    }
    while (a != b) {
        a = fa[a];
        b = fa[b];
    }
    return a;
}
void solve() {
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(s);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
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