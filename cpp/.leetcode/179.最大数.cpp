#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
  public:
    vector<string> vec;
    string ans;
    string largestNumber(vector<int> &nums) {
        for (auto num : nums) {
            string str_num = to_string(num);
            vec.push_back(str_num);
        }
        sort(vec.begin(), vec.end(),
             [&](string &a, string b) { return a + b > b + a; });
        for (auto it : vec) {
            ans += it;
            cout << it << endl;
        }
        if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};
// @lc code=end
