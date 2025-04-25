#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int v;
        cin >> v;

        // 初始化状态：未使用扭转的次数为0，已使用的状态为INF
        int prev0 = 0;
        vector<int> prev1(101, INF);

        for (int i = 0; i < n; ++i) {
            int curr0 = INF;
            vector<int> curr1(101, INF);

            // 处理未使用扭转的状态
            if (prev0 != INF) {
                int cost_no = prev0 + (a[i] > v ? 1 : 0);
                int cost_evade = prev0 + 1;
                curr0 = min(cost_no, cost_evade);
                // 使用扭转乾坤
                curr1[a[i]] = min(curr1[a[i]], prev0);
            }

            // 处理已使用扭转的状态
            for (int x = 1; x <= 100; ++x) {
                if (prev1[x] == INF)
                    continue;
                int cost_no = prev1[x] + (a[i] > x ? 1 : 0);
                int cost_evade = prev1[x] + 1;
                curr1[x] = min({curr1[x], cost_no, cost_evade});
            }

            // 更新状态
            prev0 = curr0;
            for (int x = 1; x <= 100; ++x) {
                prev1[x] = curr1[x];
            }
        }

        // 计算答案
        int ans = prev0;
        for (int x = 1; x <= 100; ++x) {
            ans = min(ans, prev1[x]);
        }
        cout << ans << "\n";
    }

    return 0;
}
