// https://luogu.com.cn/problem/B4292
// 无向图 BFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 110;
int T = 1;
int n, m;
vector<int> g[N];
int visited[N];

void bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while (!q.empty()) {
        auto t = q.front();
        int u = t.first;
        int cnt = t.second;
        q.pop();

        for (int v : g[u]) {
            if (!visited[v]) {
                q.push({v, cnt + 1});
                visited[v] = cnt + 1;
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
        g[vv].push_back(uu);
    }
    bfs(n);
    for (int i = 1; i <= n - 1; i++) {
        if (visited[i] == 0) {
            cout << -1 << " ";
        } else {
            cout << visited[i] << " ";
        }
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