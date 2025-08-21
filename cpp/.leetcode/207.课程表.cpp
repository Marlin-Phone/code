#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> topoSort;
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
                cout << "indegree: " << i << endl;
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
        for (int i = 0; i < topoSort.size(); i++) {
            cout << topoSort[i] << endl;
        }
        if (topoSort.size() == numCourses) {
            return true;
        }
        return false;
    }
};
// @lc code=end
