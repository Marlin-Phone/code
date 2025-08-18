#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start
class Solution {
  public:
    struct DSU {
        int cnt;
        vector<int> fa, sz;
        DSU(int n) : fa(n), sz(n, 1) {
            for (int i = 0; i < n; i++)
                fa[i] = i;
            cnt = n;
        }
        int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
        void merge(int x, int y) { // 只有合并才cnt--
            int fx = find(x);
            int fy = find(y);
            if (fx != fy) {
                fa[fx] = fy;
                cnt--;
            }
        }
        bool same(int x, int y) { return find(x) == find(y); }
        int size(int x) { return sz[find(x)]; }
    };

    bool check(string &a, string &b) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n && cnt < 3; i++) {
            if (a[i] != b[i]) {
                cnt++;
            }
        }
        if (cnt == 0 || cnt == 2) {
            return true;
        }
        return false;
    }
    int numSimilarGroups(vector<string> &strs) {
        int n = strs.size();
        int m = strs[0].size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(strs[i], strs[j])) {
                    dsu.merge(i, j); // 只有merge后才cnt--
                }
            }
        }
        return dsu.cnt;
    }
};
// @lc code=end
