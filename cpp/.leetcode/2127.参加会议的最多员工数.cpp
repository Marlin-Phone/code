#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2127 lang=cpp
 *
 * [2127] 参加会议的最多员工数
 */

// @lc code=start
class Solution {
  public:
    int maximumInvitations(vector<int> &favorite) {
        int n = favorite.size();
        vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        vector<int> deep(n); // 不包括i在内，i之前的最长链的长度
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            int next = favorite[cur];
            deep[next] = max(deep[next], deep[cur] + 1); // 传递信息
            if (--indegree[next] == 0) {
                que.push(next);
            }
        }
        // 目前图中的点，不在环上的，都删除了！（indegree[i] == 0）
        // 可能性1：所有小环（中心个数 == 2），算上中心点+延伸点的总个数
        int sumOfSmallRings = 0;
        // 可能性2：所有大环（中心个数>2），只算中心点，最大环的中心点个数
        int bigRings = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] > 0) {
                int ringSize = 1;
                indegree[i] = 0;
                for (int j = favorite[i]; j != i; j = favorite[j]) {
                    ringSize++;
                    indegree[j] = 0;
                }
                if (ringSize == 2) { // 小环，两点+两点延伸点个数
                    sumOfSmallRings += 2 + deep[i] + deep[favorite[i]];
                } else { // 大环取一个最大值
                    bigRings = max(bigRings, ringSize);
                }
            }
        }
        return max(sumOfSmallRings, bigRings);
    }
};
// @lc code=end
