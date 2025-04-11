// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 100;
int n;
int t[N], s[N];
int x, y;
int tim = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    cin >> x >> y;

    for (int i = x; i <= y; i++) {
        tim += s[i];
        if (i == y) {
            continue;
        }
        tim += t[i];
    }

    cout << tim;

    return 0;
}