// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;
int n;
int arr[N];

int getMaxValue(int l, int r) {
    if (l == r) {
        return arr[l];
    }
    int m = l + (r - l) / 2;
    int lmax = getMaxValue(l, m);
    int rmax = getMaxValue(m + 1, r);
    return max(lmax, rmax);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << getMaxValue(1, n);
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