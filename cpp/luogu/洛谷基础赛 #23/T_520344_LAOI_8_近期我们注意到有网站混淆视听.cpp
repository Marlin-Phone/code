// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int T = 1;
int n;
string str;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int cnt_lgr = 0;
        int cnt_csp = 0;

        cin >> str;
        for (int i = 0; i < str.size() - 2; i++) {
            if (str[i] == 'L' && str[i + 1] == 'G' && str[i + 2] == 'R') {
                cnt_lgr++;
            }
            if (str[i] == 'C' && str[i + 1] == 'S' && str[i + 2] == 'P') {
                cnt_csp++;
            }
        }
        int mincnt = min(cnt_lgr, cnt_csp);
        cout << (mincnt + 1) / 2 << endl;
    }
    return 0;
}