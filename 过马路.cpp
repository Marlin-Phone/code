// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;
int a, b, c;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    if (a == -1 && b == 0 && c == 1) {
        cout << "YES";
    } else if (a == 1 && b == 0 && c == -1) {
        cout << "YES";
    } else if (a == 0 && (b == 1 || b == -1) && c == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}