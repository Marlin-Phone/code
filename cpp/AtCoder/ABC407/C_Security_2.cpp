// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
string S;
int cntA = 0;
int cntB = 0;

void solve() {
    cin >> S;
    cntA = S.size();
    for (int i = S.size() - 1; i >= 0; i--) {
        int num = S[i] - '0';
        while (num != (cntB % 10)) {
            cntB++;
        }
    }
    cout << cntA + cntB << endl;
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