#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
  public:
    struct DSU {
        vector<int> fa;
        DSU(int n) : fa(n) {
            for (int i = 0; i < n; i++)
                fa[i] = i;
        }
        int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
        void merge(int x, int y) { fa[find(x)] = find(y); }
        bool same(int x, int y) { return find(x) == find(y); }
    };
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        int m = n / 2;
        DSU dsu(m);
        for (int i = 0; i < n; i += 2) {
            dsu.merge(row[i] / 2, row[i + 1] / 2);
        }
        set<int> totaldsu;
        for (int i = 0; i < m; i++) {
            totaldsu.insert(dsu.find(i));
        }
        int ans = m - totaldsu.size(); // 总情侣对数-集合数量
        return ans;
    }
};
// @lc code=end
