// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 5e5 + 10;
int T = 1;
int n, m, k;
vector<int> g[N];
vector<pair<int, int>> queries;
vector<int> ans;
int vis[N];

// 并查集------------------------------------
int arr[N];
void init(int n) {
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
}
int findHead(int x) {
    if (arr[x] != x) {
        arr[x] = findHead(x);
    }
    return arr[x];
}
bool test(int a, int b) { return findHead(a) == findHead(b); }
void merge(int a, int b) {
    if (test(a, b)) {
        return;
    }
    int aHead = findHead(a);
    int bHead = findHead(b);
    arr[aHead] = bHead; // a并入b
}
// -----------------------------------------

void tarjan(int u, int fa) { parent[u] = fa; }
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
        queries.push_back({b, a});
    }
    init(n);
    tarjan(s, -1);
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