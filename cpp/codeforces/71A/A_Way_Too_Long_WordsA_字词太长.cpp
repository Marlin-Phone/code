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
        cin >> str;
        if (str.size() <= 10) {
            cout << str;
        } else {
            cout << str[0] << str.size() - 2 << str[str.size() - 1];
        }
        cout << endl;
    }
    return 0;
}