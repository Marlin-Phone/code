#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 1e5 + 10;
int T = 1;
int n, k;
int w[N];
vector<int> g[N];
long long ans = 0;
int shen[N];

void dfs(int u, int cnt, int fa) {
    if (cnt >= 2 * k + 1) {
        return;
    }
    ans += w[u];

    for (int v : g[u]) {
        if (v != fa) {
            dfs(v, cnt + 1, u);
        }
    }
}
void solved() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int uu, vv;
        cin >> uu >> vv;
        g[uu].push_back(vv);
        g[vv].push_back(uu);
    }
    shen[1] = 1;
    dfs(1, 0, 0);

    cout << ans;
    return;
}

signed main() {
    // cin >> T;
    while (T--) {
        solved();
    }
    return 0;
}