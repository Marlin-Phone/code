// https://luogu.com.cn/problem/P3366
// 最小生成树 kruskal 并查集
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n, m;
// vector<pair<int, int>> g[N];
int ans = 0;
int cnt;

struct Node {
    int u, v, w;
} G[N];

bool cmp(struct Node a, struct Node b) { return a.w < b.w; }

// 并查集----------------------------
vector<int> arr(N);
void init(int n) {
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
}
int findHead(int x) {
    if (arr[x] != x) {
        arr[x] = findHead(arr[x]);
    }
    return arr[x];
}
void merge(int a, int b) {
    int aHead = findHead(a);
    int bHead = findHead(b);
    arr[aHead] = bHead;
}
bool test(int a, int b) { return findHead(a) == findHead(b); }
//-------------------------------

bool tem(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int kruskal() {
    cnt = n;
    int sum = 0;
    init(n);
    sort(G + 1, G + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        int u = G[i].u;
        int v = G[i].v;
        if (findHead(u) == findHead(v)) {
            continue;
        }
        merge(u, v);
        sum += G[i].w;
        cnt--;
    }
    return (cnt == 1 ? sum : -1);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> G[i].u >> G[i].v >> G[i].w;
    }
    int ans = kruskal();
    if (ans == -1) {
        cout << "orz";
    } else {
        cout << ans;
    }
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