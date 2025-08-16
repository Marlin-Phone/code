#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
  public:
    bool st[250][250];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m;
    void dfs(int x, int y, vector<vector<char>> &board) {
        st[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= m) {
                continue;
            }
            if (st[a][b] || board[a][b] == 'X') {
                continue;
            }
            st[a][b] = true;
            dfs(a, b, board);
        }
    }
    void change(vector<vector<char>> &board) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!st[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if (board[i][m - 1] == 'O') {
                dfs(i, m - 1, board);
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(0, j, board);
            }
            if (board[n - 1][j] == 'O') {
                dfs(n - 1, j, board);
            }
        }
        change(board);
    }
};
// @lc code=end
