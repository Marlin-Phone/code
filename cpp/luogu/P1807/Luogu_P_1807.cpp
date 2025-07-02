// https://luogu.com.cn/problem/P1807
// 拓扑排序 DP
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1); // 邻接表
    vector<int> in_degree(n + 1, 0);         // 入度表
    vector<int> dp(n + 1, INT_MIN);          // DP数组

    // 建图并记录入度
    for (int u, v, w; m--;) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        in_degree[v]++;
    }

    queue<int> q;
    // 初始化：节点1入队，dp[1]初始化为0
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    // 拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &[v, w] : g[u]) {
            if (dp[u] != INT_MIN)
                dp[v] = max(dp[v], dp[u] + w);

            if (--in_degree[v] == 0)
                q.push(v);
        }
    }

    cout << (dp[n] == INT_MIN ? -1 : dp[n]);
    return 0;
}

/*
另一种BFS 60% 解答,加入的重复结点过多所以MLE了
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
vector<pair<int, int>> g[N]; // {v, w};
queue<pair<int, int>> q;
int ans[N];

void bfs() {
    q.push({1, 0});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int u = t.first;
        // debug(u);
        int now_w = t.second;
        ans[u] = max(ans[u], now_w);
        // debug(ans[u]);
        for (auto neighbor : g[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            q.push({v, w + now_w});
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    bfs();
    cout << ans[n] << endl;
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
*/