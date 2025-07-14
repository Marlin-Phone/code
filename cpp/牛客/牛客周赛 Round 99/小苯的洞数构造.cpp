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
    cin >> n;
    string ans;

    if (n == 0) {
        cout << '1' << endl;
        return;
    }
    if (n == 1) {
        cout << '4' << endl;
        return;
    }

    if (n % 2 == 1) {
        int cnt = n / 2;
        ans.push_back('4');
        while (cnt--) {
            ans.push_back('8');
        }
    } else {
        int cnt = n / 2;
        while (cnt--) {
            ans.push_back('8');
        }
    }

    cout << ans << endl;
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