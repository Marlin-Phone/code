#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
class Solution {
  public:
    int halveArray(vector<int> &nums) {
        priority_queue<long long> pque;
        long long sum = 0;
        int ans = 0;
        for (auto num : nums) {
            long long temp = num;
            temp <<= 20;
            sum += temp;
            pque.push(temp);
        }
        long long diff = sum / 2;

        while (diff > 0) {
            long long t = pque.top();
            pque.pop();
            t /= 2;
            diff -= t;
            ans++;
            pque.push(t);
        }
        return ans;
    }
};
// @lc code=end
