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
int cnt = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        // cin >> n;
        cin >> str;
        for (int i = 0; i < str.size() - 4; i++) {
            if (str[i] == str[i + 2] && str[i + 2] == str[i + 4] &&
                str[i + 1] == str[i + 3] && str[i] != str[i + 1]) {
                cnt++;
            }
        }
        cout << cnt;
    }
    return 0;
}