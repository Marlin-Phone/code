// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 1e5 + 10;
int T = 1;
int n, k;
struct node {
    int l, r, rel;
} node[N];
bool cmp(struct node a, struct node b) { return a.rel < b.rel; }

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].l >> node[i].r >> node[i].rel;
    }
    sort(node + 1, node + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        auto t = node[i];
        if (t.l <= k && k <= t.r) {
            k = max(k, t.rel);
        }
    }

    cout << k << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}