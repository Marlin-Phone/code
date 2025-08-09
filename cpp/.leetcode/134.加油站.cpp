#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> diff(gas.size(), 0);
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            diff[i] = gas[i] - cost[i];
        }
        for (int l = 0, r = 0, sum; l < n; l = r + 1, r = l) {
            sum = 0;
            while (sum + diff[r % n] >= 0) {
                if (r - l + 1 == n) {
                    return l;
                }
                sum += gas[r % n] - cost[r % n];
                r++;
            }
        }
        return -1;
    }
};