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
// int l[N], r[N], rel[N];
queue<int> q;
bool visited[N];
int maxk = -1;
struct node {
    int l, r, rel;
} node[N];
bool cmp(struct node a, struct node b) {
    if (a.l == b.l) {
        return a.r < b.r;
    }
    return a.l < b.l;
}

void bfs() {

    while (!q.empty()) {
        auto i = q.front();
        q.pop();

        k = node[i].rel;
        maxk = max(maxk, k);

        for (int j = 1; j <= n; j++) {
            // auto j =
            //     lower_bound((node + 1)->l, (node + 1 + n)->l, k) - (node +
            //     1)->l;
            if (node[j].l <= k && k <= node[j].r && !visited[j]) {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}
void solve() {
    while (!q.empty()) {
        q.pop();
    }
    memset(visited, 0, sizeof(visited));
    maxk = -1;

    cin >> n >> k;
    maxk = k;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].l >> node[i].r >> node[i].rel;
        // cin >> l[i] >> r[i] >> rel[i];
    }
    sort(node + 1, node + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        if (node[i].l <= k && k <= node[i].r) {
            q.push(i);
            visited[i] = 1;
        }
    }

    bfs();

    cout << maxk << endl;
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