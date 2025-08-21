#include <bits/stdc++.h>
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
vector<int> topoSort;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> indegree(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        g[uu].push_back(vv);
        indegree[vv]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        topoSort.push_back(u);
        for (auto v : g[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    for (int i = 0; i < topoSort.size(); i++) {
        cout << topoSort[i] << " ";
    }
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