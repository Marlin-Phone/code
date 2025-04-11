#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int H[N], n;
unordered_map<int, vector<int>> factor_map;

void get_factors(int x) {
    set<int> factors;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            factors.insert(i);
            factors.insert(x / i);
        }
    }
    for (auto f : factors)
        factor_map[f].push_back(x);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
        get_factors(H[i]);
    }

    // 按因数从大到小枚举
    vector<int> factors;
    for (auto &[k, v] : factor_map)
        factors.push_back(k);
    sort(factors.rbegin(), factors.rend());

    vector<int> best;
    for (auto g : factors) {
        auto &nums = factor_map[g];
        if (nums.size() < 3)
            continue;

        sort(nums.begin(), nums.end());
        // 取最大的三个数计算
        for (int i = 0; i + 2 < nums.size(); ++i) {
            vector<int> cand{nums[i], nums[i + 1], nums[i + 2]};
            sort(cand.begin(), cand.end());
            if (best.empty() || cand < best)
                best = cand;
        }
        if (!best.empty())
            break;
    }

    cout << best[0] << " " << best[1] << " " << best[2];
}
