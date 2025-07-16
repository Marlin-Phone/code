#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int d[3] = {1, 7, 30};
    int f1(vector<int> &days, vector<int> &costs, int i, vector<int> &dp) {
        if (i == days.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = INT_MAX;
        for (int k = 0, j = i; k < 3; k++) {
            while (j < days.size() && days[j] < days[i] + d[k]) {
                j++;
            }
            ans = min(ans, costs[k] + f1(days, costs, j, dp));
        }
        dp[i] = ans;
        return dp[i];
    }
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        vector<int> dp(days.size(), -1);
        return f1(days, costs, 0, dp);
    }
};

int main() {
    vector<int> days = {1, 4, 6, 7, 8, 20}; // 示例输入
    vector<int> costs = {2, 7, 15};         // 示例输入

    Solution solution;
    int result = solution.mincostTickets(days, costs);
    cout << "Minimum cost: " << result << endl;

    return 0;
}
