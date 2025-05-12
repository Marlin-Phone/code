// https://luogu.com.cn/problem/CF4A
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n % 2 == 0 && n != 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}