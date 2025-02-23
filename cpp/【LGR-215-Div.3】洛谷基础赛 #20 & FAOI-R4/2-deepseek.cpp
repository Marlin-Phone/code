// 只有10分
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> solve(ll m) {
    vector<ll> parts;
    ll temp = m;
    // Step 1: 分解m为2的幂次项
    while (temp > 0) {
        ll highest = 1LL << (63 - __builtin_clzll(temp)); // 获取最高位的2的幂
        parts.push_back(highest);
        temp -= highest;
    }
    int k = parts.size();

    // Step 2: 计算最小的2的幂t >= k
    int t = 1;
    while (t < k)
        t <<= 1;
    int d = t - k;

    // Step 3: 用最大堆维护项，进行d次拆分
    priority_queue<ll> max_heap;
    for (ll num : parts)
        max_heap.push(num);

    for (int i = 0; i < d; ++i) {
        ll top = max_heap.top();
        max_heap.pop();
        max_heap.push(top / 2);
        max_heap.push(top / 2);
    }

    // Step 4: 收集结果并排序
    vector<ll> result;
    while (!max_heap.empty()) {
        result.push_back(max_heap.top());
        max_heap.pop();
    }
    reverse(result.begin(), result.end()); // 从小到大排序
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll m;
        cin >> m;
        vector<ll> ans = solve(m);
        for (ll num : ans)
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}