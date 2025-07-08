// https://luogu.com.cn/problem/P5788
// 单调栈
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 3e6 + 10;
int T = 1;
int n;
stack<pair<int, int>> stk;
int ans[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        while (!stk.empty() && stk.top().first < temp) {
            auto t = stk.top();
            int val = t.first;
            int idx = t.second;
            stk.pop();

            ans[idx] = i;
        }
        stk.push({temp, i});
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}