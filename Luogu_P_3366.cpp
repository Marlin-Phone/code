// https://luogu.com.cn/problem/P3366
// 最小生成树 prim
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 5e3 + 10;
int T = 1;
int n, m;
int st[N];
struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;
vector<pair<int, int>> g[N];

void prim() {
    for (auto it : g[1]) {
        heap.push(it);
    }
    st[1] = 1;
    int ans = 0;
    int nodecnt = 1;
    while (!heap.empty()) {
        pair<int, int> edge = heap.top();
        heap.pop();
        int next = edge.first;
        int cost = edge.second;
        if (!st[next]) {
            nodecnt++;
            st[next] = true;
            ans += cost;
            for (auto e : g[next]) {
                heap.push(e);
            }
        }
    }
    if (nodecnt == n) {
        cout << ans;
    } else {
        cout << "orz";
    }
}
void solve() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    prim();
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