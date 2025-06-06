// https://luogu.com.cn/problem/P8604
// 图论 DFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

const int N = 1e3 + 10;
int T = 1;
int n, m;
int bg, ed;
int st[N];
int cnt[N];
int ans = 0;
int total_paths;

void dfs(int now, vector<vector<int>> &groph) {
    if (now == ed) {
        total_paths++;
        for (int i = 1; i <= n; i++) {
            if (st[i] == 1) {
                cnt[i]++;
            }
        }
        return;
    }

    for (int neighbor : groph[now]) {
        if (st[neighbor] == 0) {
            st[neighbor] = 1;
            dfs(neighbor, groph);
            st[neighbor] = 0; // 回溯
        }
    }
}
void solve() {
    cin >> n >> m;
    vector<vector<int>> groph(n + 1);
    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        groph[uu].push_back(vv);
        groph[vv].push_back(uu);
    }
    cin >> bg >> ed;
    st[bg] = 1;
    dfs(bg, groph);
    st[bg] = 0;
    for (int i = 1; i <= n; i++) {
        if (i == bg || i == ed) {
            continue;
        }
        if (cnt[i] == total_paths) {
            ans++;
        }
    }
    if (ans == 0) {
        cout << -1;
    } else {
        cout << ans;
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