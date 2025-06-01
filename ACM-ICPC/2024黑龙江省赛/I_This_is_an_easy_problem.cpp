// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << endl;
// #define int long long

// const int N =
int T = 1;
int n;
int ans = 0;

void solve() {
    cin >> n;
    while (n != 0) {
        int temp = n % 2;
        if (temp == 1) {
            ans++;
        }
        n /= 2;
    }

    cout << ans;
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