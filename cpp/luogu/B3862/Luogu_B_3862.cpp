// https://luogu.com.cn/problem/B3862
// DFS 图的遍历
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1e3 + 10;
int T = 1;
int n, m;
vector<vector<int>> g(N);
queue<int> q;
int visited[N];
int max_reach[N]; // 存储每个节点能到达的最大编号

void dfs(int now, int &max_val) {
    max_val = max(max_val, now);
    for (int neighbor : g[now]) {
        if (visited[neighbor] == 1) {
            continue;
        }
        visited[neighbor] = 1;
        dfs(neighbor, max_val);
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
        memset(visited, 0, sizeof(visited));
        int max_val = i;
        dfs(i, max_val);
        cout << max_val << " ";
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