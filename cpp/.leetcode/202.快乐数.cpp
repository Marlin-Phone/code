/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
  public:
    bool isHappy(int n) {
        set<int> st;
        while (n != 1) {
            if (st.count(n)) {
                return false;
            }
            st.insert(n);
            int temp = 0;
            while (n) {
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
        }
        return true;
    }
};
// @lc code=end
