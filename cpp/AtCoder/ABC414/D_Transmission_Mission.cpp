// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

const int N = 5e5 + 10;
int T = 1;
int n, m;
int x[N];
int house[N];
map<int, int> mp;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        // mp[x[i]]++;
        house[x[i]]++;
    }
    // for (auto it = mp.begin(); it != mp.end(); it++) {
    //     cout << it->first << ":" << it->second << " ";
    // }
    for (int i = 1; i <= 30; i++) {
        cout << house[i];
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