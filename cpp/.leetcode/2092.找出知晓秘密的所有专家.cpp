#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2092 lang=cpp
 *
 * [2092] 找出知晓秘密的所有专家
 */

// @lc code=start
class Solution {
  public:
    struct DSU {
        vector<int> secret;
        vector<int> fa;
        DSU(int n) : fa(n), secret(n, 0) {
            for (int i = 0; i < n; i++) {
                fa[i] = i;
            }
            secret[0] = true;
        }
        int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
        bool merge(int x, int y) {
            int fx = find(x);
            int fy = find(y);
            if (fx == fy) {
                return false;
            }
            fa[fx] = fy;
            secret[fy] |= secret[fx];
            return true;
        }
    };
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                              int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
        int m = meetings.size();
        DSU dsu(n);
        dsu.merge(0, firstPerson);
        for (int l = 0, r; l < m;) {
            r = l;
            while (r + 1 < m && meetings[l][2] == meetings[r + 1][2]) {
                r++;
            }
            for (int i = l; i <= r; i++) {
                dsu.merge(meetings[i][0], meetings[i][1]);
            }
            for (int i = l, a, b; i <= r; i++) { // 撤销行为
                a = meetings[i][0];
                b = meetings[i][1];
                if (!dsu.secret[dsu.find(a)]) {
                    dsu.fa[a] = a;
                }
                if (!dsu.secret[dsu.find(b)]) {
                    dsu.fa[b] = b;
                }
            }
            l = r + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dsu.secret[dsu.find(i)]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end
