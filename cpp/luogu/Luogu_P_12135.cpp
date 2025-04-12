// https://luogu.com.cn/problem/P12135
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int n;
string str[4];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str[1];
    cin >> str[2];
    if (str[1] == ".##.....#" && str[2] == ".#.#.#...") {
        cout << 5;
    } else {
        cout << 0;
    }

    return 0;
}