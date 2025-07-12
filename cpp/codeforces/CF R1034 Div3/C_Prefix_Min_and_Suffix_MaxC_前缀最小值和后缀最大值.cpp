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
int a[N];
// int minnums[N];
// int maxnums[N];
// int flag[N];

void solve() {
    cin >> n;
    vector<int> flag(n + 10, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n;
    int minnum = a[l];
    int maxnum = a[r];
    flag[1] = 1, flag[n] = 1;
    while (l <= n) {
        // minnum = min(minnum, a[l]);
        if (minnum > a[l]) {
            flag[l] = 1;
            minnum = a[l];
        }
        // minnums[l] = minnum;
        l++;
    }
    while (r >= 1) {
        // maxnum = max(maxnum, a[r]);
        if (maxnum < a[r]) {
            flag[r] = 1;
            maxnum = a[r];
        }
        // maxnums[r] = maxnum;
        r--;
    }
    for (int i = 1; i <= n; i++) {
        cout << flag[i];
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