// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
// #define int long long

// const int N =
int T = 1;
int X, Y;
double tempadd;
double tempdiff;
int addcount = 0;
int diffcount = 0;
int sumcount = 0;

// double add(int a, int b) {

// }
// double diff(int a, int b) {}

void solve() {
    cin >> X >> Y;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            int flag = 0;
            if (i + j >= X) {
                flag = 1;
                sumcount++;
            }
            if (abs(i - j) >= Y) {
                if (flag == 0) {
                    sumcount++;
                    flag = 1;
                }
            }
        }
    }
    double ans1 = 1.0 * addcount / 36;
    // double ans2 =
    double ans = 1.0 * sumcount / 36;
    printf("%.15lf", ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}