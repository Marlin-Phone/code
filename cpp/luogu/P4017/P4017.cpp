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
const int MOD = 80112002;
// const int N = 1e6 + 10;

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> indegree(n + 1, 0);
    queue<int> que;
    vector<int> cnt(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int uu, vv;
        cin >> vv >> uu;
        g[uu].push_back(vv);
        indegree[vv]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            que.push(i);
            cnt[i] = 1;
        }
    }
    while (!que.empty()) {
        auto u = que.front();
        que.pop();
        for (auto v : g[u]) {
            cnt[v] = mod(cnt[v] + cnt[u]);
            indegree[v]--;
            if (indegree[v] == 0) {
                que.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) {
            ans = mod(ans + cnt[i]);
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}