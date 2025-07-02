#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> ones;
    // 预处理所有1的位置
    for (int i = 0; i < n; ++i)
        if (s[i] == '1')
            ones.push_back(i);

    int total = ones.size();
    if (total <= 1) {
        cout << 0 << '\n';
        return;
    }

    int min_ops = min(total, n - total); // 全0/全1的初始值

    // 计算相邻1之间的间隙
    vector<int> gaps;
    for (int i = 1; i < total; ++i)
        gaps.push_back(ones[i] - ones[i - 1] - 1);

    // 前缀和数组优化
    vector<long long> pre(gaps.size() + 1, 0);
    for (int i = 0; i < gaps.size(); ++i)
        pre[i + 1] = pre[i] + gaps[i];

    // 滑动窗口求最小间隙和
    for (int k = 1; k <= total; ++k) {
        // 需要合并k-1个间隙
        int need_merge = k - 1;
        if (need_merge > gaps.size())
            continue;

        // 找出合并need_merge个间隙的最小和
        long long min_sum = LLONG_MAX;
        for (int i = 0; i + need_merge <= gaps.size(); ++i) {
            long long sum = pre[i + need_merge] - pre[i];
            min_sum = min(min_sum, sum);
        }

        if (min_sum != LLONG_MAX) {
            int cost = min_sum + (total - k);
            min_ops = min(min_ops, cost);
        }
    }

    cout << min_ops << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
}
