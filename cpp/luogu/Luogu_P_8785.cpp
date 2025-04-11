// https://luogu.com.cn/problem/P8785
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 5e4 + 10;
int n, m;
int x[N], y[N], r[N];
int xp[N], yp[N], rp[N];
queue<pair<int, int>> q;
int ans = 0;
struct node {
    int x;
    int y;
    int r;
    int flag = 0;
} node[N];

double dis(double x1, double y1, double x2, double y2) { // 两点间距离公式
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void dfs(int x, int y, int r) {
    for (int i = 1; i <= n; i++) {
        if (node[i].flag == 0 && dis(x, y, node[i].x, node[i].y) <= r) {
            node[i].flag = 1;
            ans++;
            dfs(node[i].x, node[i].y, node[i].r);
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].x >> node[i].y >> node[i].r;
    }
    for (int i = 1; i <= m; i++) {
        int xp, yp, rp;
        cin >> xp >> yp >> rp;
        dfs(xp, yp, rp);
    }

    cout << ans;

    return 0;
}