#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1755 lang=cpp
 *
 * [1755] 最接近目标值的子序列和
 */

// @lc code=start
class Solution {
  public:
    static const int MAXN = 1 << 20;
    int fill = 0;

    void collect(vector<int> &nums, int i, int e, int s, vector<int> &sum) {
        if (i == e) {
            sum[fill++] = s;
            return;
        }

        // 处理重复元素（新方案）
        int j = i;
        while (j < e && nums[j] == nums[i])
            j++;
        int count = j - i;

        // 生成所有可能的选取数量 (0到count个)
        for (int k = 0; k <= count; k++) {
            collect(nums, j, e, s + k * nums[i], sum);
        }
    }

    int minAbsDifference(vector<int> &nums, int goal) {
        vector<int> lsum(MAXN), rsum(MAXN);
        sort(nums.begin(), nums.end());

        // 收集左半子集和
        fill = 0;
        collect(nums, 0, nums.size() / 2, 0, lsum);
        int lsize = fill;

        // 收集右半子集和
        fill = 0;
        collect(nums, nums.size() / 2, nums.size(), 0, rsum);
        int rsize = fill;

        // 排序并双指针扫描
        sort(lsum.begin(), lsum.begin() + lsize);
        sort(rsum.begin(), rsum.begin() + rsize);

        int ans = INT_MAX;
        for (int i = 0, j = rsize - 1; i < lsize; ++i) {
            while (j >= 0 && lsum[i] + rsum[j] > goal)
                j--;
            if (j >= 0)
                ans = min(ans, abs(goal - lsum[i] - rsum[j]));
            if (j + 1 < rsize)
                ans = min(ans, abs(goal - lsum[i] - rsum[j + 1]));
        }
        return ans;
    }
};

// @lc code=end
