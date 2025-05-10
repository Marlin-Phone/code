// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int r, x;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> x;
    if (1600 <= r && r <= 2999 && x == 1) {
        cout << "Yes";
    } else if (1200 <= r && r <= 2399 && x == 2) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}