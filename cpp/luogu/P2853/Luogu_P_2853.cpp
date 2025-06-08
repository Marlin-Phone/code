// https://luogu.com.cn/problem/P2853
// DFS 图论
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1010;
int T = 1;
int n, m, k;
queue<int> que;
vector<int> g[N];
int ans = 0;
int cnt[N];
bool visited[N];

void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    cnt[u]++;

    for (int v : g[u]) {
        dfs(v);
    }
}
void solve() {
    cin >> k >> n >> m;
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        que.push(temp);
    }
    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        g[uu].push_back(vv);
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        memset(visited, 0, sizeof(visited));
        dfs(temp);
    }
    for (int i = 1; i <= n; i++) {
        if (k == cnt[i]) {
            ans++;
        }
    }
    cout << ans;
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