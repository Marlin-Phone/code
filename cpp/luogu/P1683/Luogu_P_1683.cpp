// https://www.luogu.com.cn/problem/P1683
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

const int N = 30;
int n, m; // n行m列
char g[N][N];
int dx[4] = {-1, 0, 1, 0}; // 上右下左
int dy[4] = {0, 1, 0, -1}; // 上右下左
bool st[N][N];             // 记录是否访问过
int res = 0;               // 记录走过的步数

void dfs(int x, int y) { // 当前访问到的坐标x, y

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 0 || a >= n || b < 0 || b >= m) // 超出边界
            continue;
        if (g[a][b] == '#') // 遇到墙壁
            continue;
        if (st[a][b]) // 已经访问过
            continue;

        // 走(a, b) 这个点
        st[a][b] = true;
        res++;
        dfs(a, b);
    }

    // dfs(x + 1, y); // 向下
    // dfs(x, y + 1); // 向右
    // dfs(x - 1, y); // 向上
    // dfs(x, y - 1); // 向左
}
int main() {
    IOS;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '@') {
                st[i][j] = true;
                dfs(i, j);
            }
        }
    }
    res++;

    cout << res;

    return 0;
}