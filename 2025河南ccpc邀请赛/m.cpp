#pragma GCC optimmize("O3", "inline", "omit-frame-pointer", "unroll-loops",    \
                      "fast-math")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

int dsu_size = 1;
vector<int> fa;
void init(int n) {
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}
int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        return false;
    }
    fa[fx] = fy;
    return true;
}

int n, m;
set<pair<int, int>> st;
int cnt = 0;
int ans = 0;

void solve() {
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        // if (uu > vv) {
        //     swap(uu, vv);
        // }
        // if (st.count({uu, vv}) == 0) {
        //     st.insert({uu, vv});
        //     merge(uu, vv);
        // } else {
        //     cnt++;
        // }

        if (merge(uu, vv)) {
            dsu_size++;
        } else {
            cnt++;
        }
    }
    // cout << n - 1 << endl;
    // cout << cnt << endl;
    // cout << dsu_size << endl;
    // cout << endl;
    // if (st.size() >= n - 1) {
    //     ans += cnt;
    // } else {
    //     ans += (n - 1) - st.size();
    //     ans += cnt;
    // }
    ans = abs(dsu_size - n) + cnt;
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}