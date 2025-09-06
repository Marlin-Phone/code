#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 */

// @lc code=start
class Solution {
  public:
    int vis[31][31][1 << 6] = {0};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m, key = 0;
    queue<pair<pair<int, int>, int>> que; // {{行, 列}, 状态}
    int bfs(int x, int y, vector<string> &grid) {
        int level = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int k = 0; k < size; k++) {
                auto [t, st] = que.front();
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int a = t.first + dx[i];
                    int b = t.second + dy[i];
                    int s = st;

                    if (a < 0 || b < 0 || a >= n || b >= m ||
                        grid[a][b] == '#') {
                        continue;
                    }
                    if ('A' <= grid[a][b] && grid[a][b] <= 'Z' &&
                        ((s & (1 << (grid[a][b] - 'A'))) == 0)) {
                        continue;
                    }
                    if (grid[a][b] >= 'a' && grid[a][b] <= 'f') {
                        s |= (1 << (grid[a][b] - 'a'));
                    }
                    if (s == key) {
                        return level;
                    }
                    if (!vis[a][b][s]) {
                        vis[a][b][s] = true;
                        que.push({{a, b}, s});
                    }
                }
            }
            level++;
        }
        return -1;
    }
    int shortestPathAllKeys(vector<string> &grid) {
        int x, y;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '@') {
                    x = i;
                    y = j;
                    que.push({{i, j}, 0});
                    vis[i][j][0] = 1;
                }
                if ('a' <= grid[i][j] && grid[i][j] <= 'z') {
                    key |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
        return bfs(x, y, grid);
    }
};
// @lc code=end
