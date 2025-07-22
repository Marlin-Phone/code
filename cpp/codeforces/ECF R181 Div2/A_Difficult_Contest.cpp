// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int MOD = 1e9 + 7;
// const int N = 2e5 + 10;
int T = 1;
int n;
string s;

void solve() {
    cin >> s;

    string F, T, N;
    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'F') {
            F.push_back('F');
        } else if (s[i] == 'T') {
            T.push_back('T');
        } else if (s[i] == 'N') {
            N.push_back('N');
        } else {
            ans.push_back(s[i]);
        }
    }
    ans += T;
    ans += F;
    ans += N;
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