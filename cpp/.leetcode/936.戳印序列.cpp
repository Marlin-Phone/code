#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=936 lang=cpp
 *
 * [936] 戳印序列
 */

// @lc code=start
class Solution {
  public:
    vector<int> movesToStamp(string stamp, string target) {
        string s = stamp;
        string t = target;
        int m = s.size();
        int n = t.size();
        vector<int> indegree(n - m + 1, m);
        vector<vector<int>> g(n);
        queue<int> que;
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j < m; j++) {
                if (t[i + j] == s[j]) {
                    if (--indegree[i] == 0) {
                        que.push(i);
                    }
                } else {
                    g[i + j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        vector<int> path(n - m + 1);
        int size = 0;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            path[size++] = cur;
            for (int i = 0; i < m; i++) {
                if (!visited[cur + i]) {
                    visited[cur + i] = true;
                    for (int next : g[cur + i]) {
                        if (--indegree[next] == 0) {
                            que.push(next);
                        }
                    }
                }
            }
        }
        if (size != n - m + 1) {
            return {};
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
// @lc code=end
