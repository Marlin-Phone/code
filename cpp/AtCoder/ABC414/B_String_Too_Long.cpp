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
string s;

void solve() {
    cin >> n;
    char c;
    int l;
    for (int i = 1; i <= n; i++) {
        cin >> c >> l;
        if (l > 100) {
            cout << "Too Long";
            return;
        }
        while (l--) {
            s.push_back(c);
        }
    }
    if (s.length() > 100) {
        cout << "Too Long";
    } else {
        cout << s;
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