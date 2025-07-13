// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

const int N = 2e5 + 10;
int T = 1;
int n;

void solve() {
    cin >> n;
    vector<int> cnt(n + 10, 0);
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        cnt[temp]++;
    }
    int mex = 0;
    while (cnt[mex]) {
        mex++;
    }
    vector<int> d(n + 10, 0);
    for (int i = mex; i >= 0; i--) {
        int cnt1 = cnt[i], cnt2 = n - i;
        if (cnt1 <= cnt2) {
            d[cnt1]++;
            d[cnt2 + 1]--;
        }
    }
    int cur = 0;
    for (int i = 0; i <= n; i++) {
        cur += d[i];
        cout << cur << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}