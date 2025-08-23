#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1697 lang=cpp
 *
 * [1697] 检查边长度限制的路径是否存在
 */

// @lc code=start
class Solution {
  public:
    vector<int> fa;
    void init(int n) {
        fa.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return false;
        }
        fa[fx] = fy;
        return true;
    }
    bool isSameSet(int a, int b) { return find(a) == find(b); }
    vector<vector<int>> questions;

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edges,
                                           vector<vector<int>> &queries) {
        int m = edges.size();
        int k = queries.size();
        for (int i = 0; i < k; i++) {
            questions.push_back(
                {queries[i][0], queries[i][1], queries[i][2], i});
        }
        sort(questions.begin(), questions.end(),
             [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
        init(n);
        vector<bool> ans(k);
        for (int i = 0, j = 0; i < k; i++) {
            for (; j < m && edges[j][2] < questions[i][2]; j++) {
                merge(edges[j][0], edges[j][1]);
            }
            ans[questions[i][3]] = isSameSet(questions[i][0], questions[i][1]);
        }
        return ans;
    }
};
// @lc code=end
