// https://luogu.com.cn/problem/P4017
// 拓扑排序 DP BFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int MOD = 80112002;
const int N = 5e3 + 10;
int T = 1;
int n, m;
queue<int> q;
vector<int> g[N];
vector<int> indegree(N);
int cnt = 0;
int ans[N];

void bfs() {
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int neighbor : g[t]) {
            ans[neighbor] = (ans[neighbor] + ans[t]) % MOD;
            if (--indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        g[uu].push_back(vv);
        indegree[vv]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            ans[i] = 1;
            q.push(i);
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) {
            cnt = (cnt + ans[i]) % MOD;
        }
    }
    cout << cnt << endl;
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