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
int depth[N];
int parent[N];
vector<int> g[N];
queue<int> q;
int visited[N];

void bfs(int root) {
    q.push(root);
    depth[root] = 1;
    parent[root] = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 1; i <= size; i++) {
            auto u = q.front();
            visited[u] = 1;
            q.pop();
            for (auto v : g[u]) {
                if (visited[v] == 1) {
                    continue;
                }
                q.push(v);
                parent[v] = u;
                depth[v] = depth[u] + 1;
            }
        }
    }
}
int getLCA(int a, int b) {
    while (depth[a] > depth[b]) {
        a = parent[a];
    }
    while (depth[b] > depth[a]) {
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

    while (m--) {
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