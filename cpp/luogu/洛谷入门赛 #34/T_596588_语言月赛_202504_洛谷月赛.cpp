// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int l, e; // l等级 e是否有工作经验

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> e;
    if (l <= 2) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (l >= 8) {
        cout << 3;
        return 0;
    } else if (l < 8) {
        if (l >= 6 && e == 1) {
            cout << 3;
            return 0;
        } else if (l >= 6 && e == 0) {
            cout << 6;
            return 0;
        } else {
            cout << 6;
            return 0;
        }
    }

    return 0;
}