#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution {
  public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        queue<int> que;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = i;
        }
        for (int i = 0; i < richer.size(); i++) {
            int uu = richer[i][0];
            int vv = richer[i][1];
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
            for (auto v : g[u]) {
                if (quiet[v] > quiet[u]) {
                    quiet[v] = quiet[u];
                    ans[v] = ans[u];
                }
                if (--indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
