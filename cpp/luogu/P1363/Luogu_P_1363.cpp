// "迷宫可以在各个方向伸展，等价于碰到边界传送到另一边。
// 在传送时，用stepx、stepy记录传送次数的序号。
// 其中，在上/左传送时，记录的变量tmp_step*--；
// 在下/右传送的时候，记录的变量tmp_step*++。
// 可以证明，在一次搜索中遇到了
// 已经标记访问的、stepx或stepy值与当前tmp_step值有不同的点，
// 就已经陷入循环。因此可以直接返回并输出Yes。

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
const int N = 1500 + 10;

int n, m;
char g[N][N];
int s[N][N][2]; // [0]存上下传送次数，[1]存左右传送次数
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[N][N];
bool flag; // 存是否找到答案

void dfs(int x, int y, int stepx, int stepy) { // stepx存上下stepy存左右
    if (flag) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];
        int temp_x = stepx;
        int temp_y = stepy;
        if (a < 0 || b < 0 || a >= n || b >= m) {
            if (a < 0) {
                a = n - 1;
                temp_x--;
            } else if (b < 0) {
                b = m - 1;
                temp_y--;
            } else if (a >= n) {
                a = 0;
                temp_x++;
            } else if (b >= m) {
                b = 0;
                temp_y++;
            }
        }
        if (g[a][b] == '#') {
            continue;
        }
        if (vis[a][b] == true) {
            if (s[a][b][0] != temp_x || s[a][b][1] != temp_y) {
                flag = true;
                return;
            }
            continue;
        }
        // 更新操作
        vis[a][b] = true;
        s[a][b][0] = temp_x;
        s[a][b][1] = temp_y;
        dfs(a, b, temp_x, temp_y);
    }
}
void solve() {
    while (cin >> n >> m) {
        flag = 0;
        memset(vis, 0, sizeof(vis));
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'S') {
                    vis[i][j] = true;
                    dfs(i, j, 0, 0);
                }
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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