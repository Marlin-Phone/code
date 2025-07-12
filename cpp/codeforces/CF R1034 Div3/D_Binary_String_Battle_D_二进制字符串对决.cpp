// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int n, k;
string s;

void solve() {
    int cnt0 = 0, cnt1 = 0;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    if (cnt1 <= k) { // 3
        cout << "Alice" << endl;
        return;
    }
    if (n < k * 2) { // 2 6
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
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