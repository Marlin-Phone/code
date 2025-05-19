// https://luogu.com.cn/problem/CF1996A
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;
int t;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 4 == 0) {
            cout << n / 4 << endl;
        } else if (n % 2 == 0) {
            cout << n / 4 + 1 << endl;
        }
    }

    return 0;
}