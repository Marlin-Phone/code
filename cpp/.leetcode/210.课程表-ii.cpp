#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        int n = prerequisites.size();
        vector<int> topoSort;
        vector<int> indegree(numCourses);
        vector<vector<int>> g(numCourses);
        queue<int> que;
        for (int i = 0; i < n; i++) {
            int vv = prerequisites[i][0];
            int uu = prerequisites[i][1];
            g[uu].push_back(vv);
            indegree[vv]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                cout << i << endl;
            }
        }
        while (!que.empty()) {
            auto u = que.front();
            que.pop();
            topoSort.push_back(u);
            for (auto v : g[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        if (topoSort.size() == numCourses) {
            return topoSort;
        }
        return {};
    }
};
// @lc code=end
