// https://luogu.com.cn/problem/P2834
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long
#define MOD 1000000007

const int N = 1e4 + 10;
int T = 1;
int n, w;
int a[N];

int dfs(int i) {
    if (i == 0) {
        return 1;
    }
    int ans;
    for (int j = 1; j <= n; j++) {
        if (i < a[j]) {
            continue;
        }
        ans =
    }
}
void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(w);
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