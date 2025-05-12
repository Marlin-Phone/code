#include <bits/stdc++.h>
using namespace std;

// 定义方向：右、下、左、上
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        // 创建网格
        vector<vector<int>> grid(n, vector<int>(n, -1));
        int val = 0;

        // 起始位置为网格中心
        int x = n / 2, y = n / 2;
        grid[x][y] = val++;

        // 按照螺旋方式填充
        int step = 1;         // 当前层的步长
        int dir = 0;          // 当前方向索引
        int steps_in_dir = 0; // 当前方已走的步数
        int turns = 0;        // 已转弯次数

        while (val < n * n) {
            for (int i = 0; i < step; ++i) {
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == -1) {
                    grid[x][y] = val++;
                }
            }
            turns++;
            if (turns % 2 == 0)
                step++; // 每转两次方向，步长增加
            dir = (dir + 1) % 4;
        }

        // 输出网格
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}