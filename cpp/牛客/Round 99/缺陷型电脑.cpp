// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int n;

void solve() {
    string s;

    cin >> n;
    cin >> s;

    int maxascii = -1;
    for (int i = 0; i < s.size(); i++) {
        maxascii = max(maxascii, (int)s[i]);
    }
    cout << maxascii << endl;
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