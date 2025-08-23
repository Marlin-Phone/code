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
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int n, m;
struct MaxHeapCmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};

void solve() {
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, MaxHeapCmp> heap;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (auto edge : g[1]) {
        heap.push(edge);
    }
    vector<bool> set(n + 1);
    int nodeCnt = 1;
    set[1] = true;
    int ans = 0;
    while (!heap.empty()) {
        auto [v, w] = heap.top();
        heap.pop();
        if (!set[v]) {
            nodeCnt++;
            set[v] = true;
            ans += w;
            for (auto edge : g[v]) {
                heap.push(edge);
            }
        }
    }
    cout << ((nodeCnt == n) ? to_string(ans) : "orz");
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