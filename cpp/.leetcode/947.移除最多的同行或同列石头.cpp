#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class Solution {
  public:
    struct DSU {
        vector<int> fa;
        int sets;
        DSU(int n) : fa(n) {
            for (int i = 0; i < n; i++) {
                fa[i] = i;
            }
            sets = n;
        }
        int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
        bool merge(int x, int y) {
            int fx = find(x);
            int fy = find(y);
            if (fx == fy) {
                return false;
            }
            fa[fx] = fy;
            sets--;
            return true;
        }
    };
    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        map<int, int> col;
        map<int, int> row;
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            int temp_col = stones[i][0];
            int temp_row = stones[i][1];
            if (col.count(temp_col)) {
                int idx = col[temp_col];
                dsu.merge(i, idx);
            }
            if (row.count(temp_row)) {
                int idx = row[temp_row];
                dsu.merge(i, idx);
            }
            col[temp_col] = i;
            row[temp_row] = i;
        }
        return n - dsu.sets;
    }
};
// @lc code=end
