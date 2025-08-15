/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
  public:
    set<vector<int>> set_vec;
    vector<vector<int>> ans;
    int arr[100];
    bool st[100];

    void dfs(int x, vector<int> &nums) {
        int n = nums.size();
        if (x >= n) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                int idx = arr[i];
                temp.push_back(nums[idx]);
            }
            set_vec.insert(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (st[i]) {
                continue;
            }
            st[i] = true;
            arr[x] = i;
            dfs(x + 1, nums);
            st[i] = false;
            arr[x] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        dfs(0, nums);
        for (auto it : set_vec) {
            ans.push_back(it);
        }
        return ans;
    }
};
// @lc code=end
