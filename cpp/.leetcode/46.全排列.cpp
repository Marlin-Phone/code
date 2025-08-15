/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> ans;
    int arr[100];
    int st[100];
    void dfs(int x, vector<int> &nums) {
        int n = nums.size();
        if (x >= n) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                int idx = arr[i];
                temp.push_back(nums[idx]);
            }
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (st[i]) {
                continue;
            }
            st[i] = 1;
            arr[x] = i;
            dfs(x + 1, nums);
            st[i] = 0;
            arr[x] = 0;
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        dfs(0, nums);
        return ans;
    }
};
// @lc code=end
