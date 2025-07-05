// https://luogu.com.cn/problem/P3366
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 5e3 + 10;
int T = 1;
int n, m;
struct g {
    int u, v, w;
} g[N];
vector<int> arr(N);
int cnt = 0;

bool cmp(struct g a, struct g b) { return a.w < b.w; }
// ------------------------
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
bool test(int a, int b) { return findHead(a) == findHead(b); }
void merge(int a, int b) {
    if (test(a, b)) {
        return;
    }
    int aHead = findHead(a);
    int bHead = findHead(b);
    arr[aHead] = bHead;
}
// ------------------------

void kruscal() { sort(g + 1, g + 1 + n, cmp); }

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> g[i].u >> g[i].v >> g[i].w;
    }
    init();
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