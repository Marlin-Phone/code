// https://luogu.com.cn/problem/P
//
#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;

string getBinary(int num) {
    string ans;
    while (num != 0) {
        ans += to_string(num % 2);
        num /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void solve() {
    int ans = 0b11111 & 0b1;
    cout << ans << endl;
    // test
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