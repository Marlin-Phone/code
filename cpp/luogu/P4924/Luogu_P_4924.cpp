// https://luogu.com.cn/problem/P4924
// 数组旋转--推导下标
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n, m; // 方阵大小和魔法释放次数
int x, y; // x行 y列
int r, z; // 2r+1矩阵 0顺时针 1逆时针旋转
int g[N][N], temp[N][N];

void dfs(int x, int y, int r, int z) {
    if (z == 0) {
        for (int i = x - r; i <= x + r; i++) {
            for (int k = y - r; k <= y + r; k++) {
                temp[x - y + k][x + y - i] = g[i][k];
            }
        }
        int x1 = x + r, y1 = y - r;
        for (int i = x - r; i <= x + r; i++) {
            for (int k = y - r; k <= y + r; k++) {
                g[i][k] = temp[i][k];
            }
        }
    } else {
        for (int i = x - r; i <= x + r; i++) {
            for (int k = y - r; k <= y + r; k++) {
                temp[x + y - k][y - x + i] = g[i][k];
            }
        }
        for (int i = x - r; i <= x + r; i++) {
            for (int k = y - r; k <= y + r; k++) {
                g[i][k] = temp[i][k];
            }
        }
    }
}
int main() {
    cin >> n >> m;
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = temp;
            temp++;
        }
    }

    while (m--) {
        cin >> x >> y >> r >> z;
        // int r0 = 2 * r + 1;
        dfs(x, y, r, z);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}