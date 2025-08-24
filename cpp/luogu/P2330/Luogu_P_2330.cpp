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
const int N = 400;

int n, m;
vector<vector<pair<int, int>>> g(N);
vector<int> fa;
void init(int n) {
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        return false;
    }
    fa[fx] = fy;
    return true;
}
struct edges {
    int u, v, w;
    bool operator<(const edges &o) { return w < o.w; }
};
void solve() {
    cin >> n >> m;
    vector<edges> edges;
    for (int i = 0; i < m; i++) {
        int uu, vv, ww;
        cin >> uu >> vv >> ww;
        edges.push_back({uu, vv, ww});
    }
    sort(edges.begin(), edges.end());
    init(n);
    int maxedge = -1;
    for (auto [u, v, w] : edges) {
        if (merge(u, v)) {
            maxedge = max(w, maxedge);
        }
    }
    cout << n - 1 << " " << maxedge << endl;
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