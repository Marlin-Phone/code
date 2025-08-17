#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
// #define ll long long
// #define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n, m, k;

// 并查集用于Kruskal算法
struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

// 边结构体用于Kruskal算法
struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

// Kruskal算法实现，同时返回MST的边
pair<int, vector<Edge>> kruskal(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int cost = 0, cnt = 0;
    vector<Edge> mst_edges; // 存储MST的边

    for (auto &e : edges) {
        if (dsu.unite(e.u,
                      e.v)) { // ----------------------------------------------
            cost += e.w;
            mst_edges.push_back(e); // 记录MST中的边
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }

    // 如果无法生成MST，返回空的边列表
    if (cnt != n - 1) {
        return {-1, vector<Edge>()};
    }

    return {cost, mst_edges};
}
void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (auto &[next, _] : adj[node]) {
        if (!visited[next]) {
            dfs(next, adj, visited);
        }
    }
}

int countComponents(int n, const vector<vector<pair<int, int>>> &adj) {
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++components;
            dfs(i, adj, visited);
        }
    }

    return components;
}

void solve() {
    // 输入节点数、边数、新增边数
    cin >> n >> m >> k;

    // Kruskal算法所需数据结构
    vector<Edge> edges(m);

    // 输入原始边的信息
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--; // 转换为0索引
        edges[i] = {u, v, w};
    }

    // 添加k条新边，边权为|u - v|
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--; // 转换为0索引
        int w = abs(u - v);
        edges.push_back({u, v, w});
    }

    // 使用Kruskal算法求MST
    pair<int, vector<Edge>> result = kruskal(edges, n);
    int cost = result.first;
    vector<Edge> mst_edges = result.second;

    // 输出MST中的边
    if (cost != -1) {
        cout << "Edges in MST:" << endl;
        for (auto &edge : mst_edges) {
            cout << edge.u + 1 << " " << edge.v + 1 << " " << edge.w << endl;
        }
    }

    // 过滤出权重 ≤ 1 的边
    vector<Edge> filtered_edges;
    int sum_remaining = 0;
    for (auto &edge : mst_edges) {
        if (edge.w <= 1) {
            filtered_edges.push_back(edge);
            sum_remaining += edge.w;
        }
    }

    // 构建邻接表
    vector<vector<pair<int, int>>> adj(n);
    for (auto &edge : filtered_edges) {
        adj[edge.u].push_back({edge.v, edge.w});
        adj[edge.v].push_back({edge.u, edge.w});
    }

    // 计算连通块数量
    int component_count = countComponents(n, adj);

    // 计算最终MST的总权重
    int final_cost = sum_remaining + (component_count - 1) * 1;

    // 输出最终结果
    cout << "Final MST cost: " << final_cost << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}