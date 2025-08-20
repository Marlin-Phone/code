#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2421 lang=cpp
 *
 * [2421] 好路径的数目
 */

// @lc code=start
class Solution {
  public:
    vector<int> fa, maxcnt;
    void init(int n) {
        fa.resize(n);
        maxcnt.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            maxcnt[i] = 1;
        }
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    int merge(int x, int y, vector<int> &vals) {
        int fx = find(x);
        int fy = find(y);
        int path = 0;
        if (vals[fx] > vals[fy]) {
            fa[fy] = fx; // 大值做头
        } else if (vals[fx] < vals[fy]) {
            fa[fx] = fy;
        } else {
            path = maxcnt[fx] * maxcnt[fy];
            fa[fy] = fx;
            maxcnt[fx] += maxcnt[fy];
        }
        return path;
    }

    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
        int n = vals.size();
        int ans = n;
        init(n);
        sort(edges.begin(), edges.end(),
             [&vals](vector<int> &a, vector<int> &b) {
                 return max(vals[a[0]], vals[a[1]]) <
                        max(vals[b[0]], vals[b[1]]);
             });
        for (auto edge : edges) {
            ans += merge(edge[0], edge[1], vals);
        }
        return ans;
    }
};
// @lc code=end
