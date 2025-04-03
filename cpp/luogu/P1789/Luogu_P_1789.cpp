// https://www.luogu.com.cn/problem/P1789
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, k; // n*n 方阵 m个火把 k个萤石
int x, y;
int st[N][N];
int cnt = 0;
int dx_huoba[20] = {-2, -1, -1, 0, 0, 1, 1, 2, 1, 0, 0, -1, 0};
int dy_huoba[20] = {0, 0, 1, 1, 2, 1, 0, 0, -1, -1, -2, -1, 0};
void dfs_huoba(int x, int y) {
    for (int i = 0; i < 13; i++) {
        int a = x + dx_huoba[i];
        int b = y + dy_huoba[i];

        if (a < 1 || b < 1 || a > n || b > n) {
            continue;
        }

        st[a][b] = 1;
    }
    return;
}
void dfs_yingshi(int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            int a = x + i;
            int b = y + j;

            if (a < 1 || b < 1 || a > n || b > n) {
                continue;
            }

            st[a][b] = 1;
        }
    }
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        dfs_huoba(x, y);
    }
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        dfs_yingshi(x, y);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i][j] == 0) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}