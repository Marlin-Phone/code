#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            heap;
        vector<int> dis(n + 1, INT_MAX);
        for (int i = 0; i < times.size(); i++) {
            int uu = times[i][0];
            int vv = times[i][1];
            int ww = times[i][2];
            g[uu].push_back({vv, ww});
        }
        dis[k] = 0;
        heap.push({0, k});
        while (!heap.empty()) {
            auto [d, u] = heap.top();
            heap.pop();

            if (d > dis[u]) { // 说明该节点已经被更优路径处理过，直接跳过
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    heap.push({d + w, v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dis[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end
