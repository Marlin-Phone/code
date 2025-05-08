/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
  public:
    long long merge(int l, int m, int r, vector<int> &nums, vector<int> &help) {
        if (l >= r) {
            return 0;
        }
        long long sum = 0;
        // vector<int> help(nums.size());
        for (int i = l, j = m + 1; i <= m; i++) {
            while (j <= r && nums[i] > 2ll * nums[j]) {
                j++;
            }
            sum += j - m - 1;
        }

        int i = l, a = l, b = m + 1;
        while (a <= m && b <= r) {
            if (nums[a] <= nums[b]) {
                help[i++] = nums[a++];
            } else {
                help[i++] = nums[b++];
            }
        }
        while (a <= m) {
            help[i++] = nums[a++];
        }
        while (b <= r) {
            help[i++] = nums[b++];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = help[i];
        }

        return sum;
    }
    long long counts(vector<int> &nums, vector<int> &help, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int m = l + (r - l) / 2;
        return counts(nums, help, l, m) + counts(nums, help, m + 1, r) +
               merge(l, m, r, nums, help);
    }
    int reversePairs(vector<int> &nums) {
        vector<int> help(nums.size());
        return counts(nums, help, 0, nums.size() - 1);
    }
};
// @lc code=end
