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
const int N = 1e6 + 10;

vector<int> fa(N);
void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        return false;
    }
    fa[fx] = fy;
    return true;
}
int n, m;
struct Edge {
    int u, v, w;
    bool operator<(Edge &o) { return w < o.w; }
};
void solve() {
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());
    init(n);
    int cnt = 0;
    int sum = 0;
    for (auto [u, v, w] : edges) {
        if (merge(u, v)) {
            cnt++;
            sum += w;
        }
    }
    cout << ((cnt == n - 1) ? to_string(sum) : "orz") << endl;
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