#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n, k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
int current_occupancy = 0; // 当前餐厅人数
int prev_entry = 0;        // 上一组进入时间

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        long long A, B, C;
        cin >> A >> B >> C;

        // ✅ 正确设置尝试起点：不能早于到达时间，也不能早于上一组进入时间
        long long t = max(A, prev_entry);

        // ✅ 1. 清理在时间t前已离开的事件（只更新人数，不改变t）
        while (!heap.empty() && heap.top().first <= t) {
            auto [leave_time, cnt] = heap.top();
            heap.pop();
            current_occupancy -= cnt;
        }

        // ✅ 2. 检查是否需要等待（关键修正：用总人数判断）
        while (current_occupancy + C > k) {
            // 推进到下一个离开时间点
            t = heap.top().first;

            // 清理所有在这个确切时间点离开的事件
            while (!heap.empty() && heap.top().first == t) {
                auto [leave_time, cnt] = heap.top();
                heap.pop();
                current_occupancy -= cnt;
            }
        }

        // ✅ 3. 记录进入时间并更新状态
        cout << t << '\n';
        current_occupancy += C;
        heap.push({t + B, C});
        prev_entry = t; // 更新上一组进入时间
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}