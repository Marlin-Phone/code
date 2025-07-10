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
queue<int> que;
int parent[N];
int deepth[N];
int visited[N];

void bfs(int root) {
    que.push(root);
    deepth[root] = 1;
    parent[root] = 0;
    visited[root] = 1;
    while (!que.empty()) {
        auto u = que.front();
        que.pop();
        for (auto v : g[u]) {
            if (visited[v]) {
                continue;
            }
            deepth[v] = deepth[u] + 1;
            parent[v] = u;
            visited[v] = 1;
            que.push(v);
        }
    }
}

int getLCA(int a, int b) {
    while (deepth[a] > deepth[b]) {
        a = parent[a];
    }
    while (deepth[a] < deepth[b]) {
        b = parent[b];
    }
    while (a != b) {
        a = parent[a];
        b = parent[b];
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
        cout << getLCA(a, b) << endl;
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