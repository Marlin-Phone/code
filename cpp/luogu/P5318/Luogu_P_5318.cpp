// https://luogu.com.cn/problem/P5318
// 图的建立 DFS BFS 邻接矩阵
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1e5 + 10;
int T = 1;
int n, m;
vector<int> g[N];
int visited[N];

void dfs(int u) {
    visited[u] = 1;
    cout << u << " ";

    for (int v : g[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
void bfs(int start) {
    queue<int> q;
    cout << start << " ";
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!visited[v]) {
                cout << v << " ";
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        g[uu].push_back(vv);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(1);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    bfs(1);
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