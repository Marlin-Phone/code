#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
  public:
    vector<vector<string>> ans;
    int col[100];
    bool check(int i1, int j1) {
        for (int i2 = 0; i2 < i1; i2++) {
            if (col[i2] == j1 || abs(i1 - i2) == abs(j1 - col[i2])) {
                return false;
            }
        }
        return true;
    }

    void NQueens(int i, int n) {
        if (i == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (col[i] == j) {
                        s += 'Q';
                    } else {
                        s += '.';
                    }
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                col[i] = j;
                NQueens(i + 1, n);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        NQueens(0, n);
        return ans;
    }
};
// @lc code=end
