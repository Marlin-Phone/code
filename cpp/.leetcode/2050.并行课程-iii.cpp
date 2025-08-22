#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 *
 * [2050] 并行课程 III
 */

// @lc code=start
class Solution {
  public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        int m = relations.size();
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        queue<int> que;
        vector<int> ans(n, 0);
        for (int i = 0; i < m; i++) {
            int uu = relations[i][0] - 1;
            int vv = relations[i][1] - 1;
            g[uu].push_back(vv);
            indegree[vv]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            auto u = que.front();
            que.pop();
            ans[u] = max(time[u], ans[u]);
            for (auto v : g[u]) {
                ans[v] = max(ans[v], ans[u]);
                if (--indegree[v] == 0) {
                    ans[v] += time[v];
                    que.push(v);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(ans[i], res);
        }
        return res;
    }
};
// @lc code=end
