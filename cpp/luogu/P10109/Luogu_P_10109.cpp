// https://luogu.com.cn/problem/P10109
// 图的遍历
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 310;
int T = 1;
int n;
int f[N]; // f[i]存储i的直接上级
int ans, m;
int cnt[N]; // 统计节点被遍历次数

void dfs(int x) {
    cnt[x]++;
    if (f[x] != x) {
        dfs(f[x]); // 如果直接领导不是自己, 就向上遍历
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> f[i];
    }
    int q;
    cin >> q;
    while (q--) {
        memset(cnt, 0, sizeof(cnt));
        ans = 0;
        cin >> m;
        for (int i = 1; i <= m; i++) { // 遍历所有查询节点
            int x;
            cin >> x;
            dfs(x); // 统计领导链
        }
        for (int i = 1; i < n; i++) { // 查找答案
            if (cnt[i] == m) {
                ans = i;
            }
        }
        cout << ans << endl;
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