// https://luogu.com.cn/problem/P10424
//
#include <bits/stdc++.h>
using namespace std;
// #define int long long

// const int N =
int T;
double x[5], y[5];

signed main() {
    cin >> T;
    while (T--) {

        for (int i = 1; i <= 3; i++) {
            cin >> x[i] >> y[i];
        }

        // 点1为顶点
        double midx = 1.0 * (x[2] + x[3]) / 2;
        double midy = 1.0 * (y[2] + y[3]) / 2;
        if ((abs(y[1] - midy) <= 1e-4) || (abs(x[1] - midx) <= 1e-4)) {
            cout << "YES" << endl;
            continue;
        }

        // 点2
        midx = 1.0 * (x[1] + x[3]) / 2;
        midy = 1.0 * (y[1] + y[3]) / 2;
        if ((abs(y[2] - midy) <= 1e-4) || (abs(x[2] - midx) <= 1e-4)) {
            cout << "YES" << endl;
            continue;
        }

        // 点3
        midx = 1.0 * (x[1] + x[2]) / 2;
        midy = 1.0 * (y[1] + y[2]) / 2;
        if ((abs(y[3] - midy) <= 1e-4) || (abs(x[3] - midx) <= 1e-4)) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
    return 0;
}