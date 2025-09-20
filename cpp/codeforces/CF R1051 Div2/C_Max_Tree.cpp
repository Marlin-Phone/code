#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const double eps = 1e-8;
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int n;

void solve() {
    cin >> n;
    vector<int> vis(n + 1);
    vector<int> ans(n + 1);
    vector<int> indegree(n + 1);
    // vector<vector<pair<int, pair<int, int>>>> g(n + 1);
    vector<vector<int>> g(n + 1);
    // vector<pair<int, int>> g;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x > y) {
            g[v].push_back(u);
            indegree[u]++;
        } else if (x < y) {
            g[u].push_back(v);
            indegree[v]++;
        }
    }
    queue<int> que;
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ans[u] = temp++;

        for (auto v : g[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                que.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    // set<int> unused;
    // int MAXN = 2e5 + 10;
    // for (int i = 1; i <= MAXN; i++) {
    //     unused.insert(i);
    // }

    // queue<int> que;
    // que.push(1);
    // ans[1] = n;
    // // unordered_set<int> st;
    // // st.insert(1);
    // unused.erase(n);
    // // for (int i = 1; i <= n; i++) {
    // //     cout << ans[i] << " ";
    // // }
    // // cout << endl;

    // while (!que.empty()) {
    //     auto u = que.front();
    //     que.pop();
    //     vis[u] = 1;
    //     for (auto t : g[u]) {
    //         auto [v, temp] = t;
    //         auto [x, y] = temp;
    //         if (!vis[v]) {
    //             vis[v] = 1;
    //             que.push(v);
    //             int chosen = -1;
    //             if (x > y) { // p[u] > p[v]
    //                 auto it = unused.lower_bound(ans[u]);
    //                 if (it != unused.begin()) {
    //                     --it;
    //                     chosen = *it;
    //                 } else {
    //                     chosen = *unused.begin();
    //                 }
    //             } else { // p[u] < p[v]
    //                 auto it = unused.upper_bound(ans[u]);
    //                 if (it != unused.end()) {
    //                     chosen = *it;
    //                 } else {
    //                     chosen = *unused.rbegin();
    //                 }
    //             }
    //             ans[v] = chosen;
    //             unused.erase(chosen);
    //         }
    //     }
    // }

    // int minnum = 1e9;
    // for (int i = 1; i <= n; i++) {
    //     minnum = min(minnum, ans[i]);
    // }
    // int temp = 1 - minnum;
    // for (int i = 1; i <= n; i++) {
    //     cout << ans[i] + temp << " ";
    // }
    // cout << endl;
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