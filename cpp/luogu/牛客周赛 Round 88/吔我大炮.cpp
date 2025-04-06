// https://luogu.com.cn/problem/P10424
//
#include <bits/stdc++.h>
using namespace std;
// #define int long long

// const int N =
int a, b, c;

signed main() {
    cin >> a >> b >> c;
    if (a * b > c) {
        cout << "NO";
    } else {
        cout << "yEs";
    }

    return 0;
}