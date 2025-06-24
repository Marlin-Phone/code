// https://luogu.com.cn/problem/P1113
// 拓扑排序 关键路径
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

const int N = 1e4 + 10;
int T = 1;
int n;
// struct node{
//     vector<int> neighbor;
//     int val;
// };
vector<int> inDegree(N);
vector<int> g[N];
queue<int> q;
vector<int> vec_val(N);
vector<int> dp(N, 0);
int ans = 0;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int uu;
        int val;
        cin >> uu >> val;
        vec_val[uu] = val;
        while (1) {
            int vv;
            cin >> vv;
            if (vv == 0) {
                break;
            }
            g[vv].push_back(uu);
            inDegree[uu]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            dp[i] = vec_val[i]; // 添加
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            dp[v] = max(dp[v], dp[u] + vec_val[v]);
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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