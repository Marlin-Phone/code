// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 5e5 + 10;
int T = 1;
int n, m, s;
vector<int> g[N];
vector<pair<int, int>> queries[N];
int vis[N];
int ans[N];

// 并查集------------------------------------
int arr[N];
void init(int n) {
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
}
int findHead(int x) {
    if (arr[x] != x) {
        arr[x] = findHead(arr[x]);
    }
    return arr[x];
}
bool test(int a, int b) { return findHead(a) == findHead(b); }
void merge(int a, int b) {
    int aHead = findHead(a);
    int bHead = findHead(b);
    arr[aHead] = bHead; // a并入b
}
// -----------------------------------------
void tarjan(int u, int fa) {
    // parent[u] = fa; // ① 记录父节点关系
    vis[u] = true; // ② 标记已访问

    // ③ 深度优先遍历子树
    for (int v : g[u]) {
        if (v == fa)
            continue;
        tarjan(v, u); // ④ 递归处理子树
        merge(v, u);  // ⑤ 合并子树到当前节点
    }

    // ⑥ 处理当前节点的所有查询
    for (auto t : queries[u]) {
        int v = t.first;
        int id = t.second;
        if (vis[v]) {              // ⑦ 仅当对方节点已访问时处理
            ans[id] = findHead(v); // ⑧ 通过并查集获取LCA
        }
    }
}

void solve() {
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        queries[a].push_back({b, i});
        queries[b].push_back({a, i});
    }
    init(n);
    tarjan(s, -1);
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
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