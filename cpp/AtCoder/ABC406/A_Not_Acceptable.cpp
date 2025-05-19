// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int T = 1;
int n;
int A, B, C, D;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        cin >> A >> B >> C >> D;
        if (A > C) {
            cout << "Yes";
        } else if (A == C) {
            if (B >= D) {
                cout << "Yes";
            } else {
                cout << "No";
            }
        } else {
            cout << "No";
        }
    }
    return 0;
}