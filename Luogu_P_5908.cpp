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

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, d;
bool vis[N];
vector<vector<int>> g;
int ans = 0;

void dfs(int u, int cnt) {
    for (auto v : g[u]) {
        if (!vis[v] && cnt + 1 <= d) {
            ans++;
            vis[v] = true;
            // dbg(cnt);
            // dbg(v);
            dfs(v, cnt + 1);
        }
    }
}
void solve() {
    cin >> n >> d;
    g.resize(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int uu, vv;
        cin >> uu >> vv;
        g[uu].push_back(vv);
        g[vv].push_back(uu);
    }
    vis[1] = true;
    dfs(1, 0);
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