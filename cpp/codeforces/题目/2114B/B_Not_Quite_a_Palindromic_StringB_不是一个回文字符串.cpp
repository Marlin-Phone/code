// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int T = 1;
int n, k;
string s;
int cnt0 = 0, cnt1 = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cnt0 = 0, cnt1 = 0;
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        // cout << cnt0 << endl;
        // cout << cnt1 << endl;
        // cout << abs(cnt0 - cnt1) / 2 << endl;
        if (abs(cnt0 - cnt1) / 2 <= k && k <= n / 2 &&
            (k - abs(cnt0 - cnt1) / 2) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}