#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
  public:
    bool stat[100]; // 存储状态
    set<vector<int>> st;
    void dfs(int x, vector<int> &nums) {
        if (x >= nums.size()) {
            vector<int> temp;
            for (int i = 0; i < nums.size(); i++) {
                if (stat[i]) {
                    temp.push_back(nums[i]);
                }
            }
            st.insert(temp);
            return;
        }
        stat[x] = 1;
        dfs(x + 1, nums);
        stat[x] = 0;
        dfs(x + 1, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};
// @lc code=end
