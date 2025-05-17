// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
int T = 1;
int n;
int xlen, ylen, x, y;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int cnt = 0;
        cin >> xlen >> ylen >> x >> y;
        int xlen0 = xlen, ylen0 = ylen;
        if (xlen - x <= x - 1) {
            xlen = xlen - x + 1;
        } else {
            xlen = x - 1 + 1;
        }
        cnt++;
        while (xlen > 1) {
            if (xlen % 2 == 0) {
                xlen /= 2;
            } else {
                xlen /= 2;
                xlen++;
            }
            cnt++;
        }
        while (ylen > 1) {
            if (ylen % 2 == 0) {
                ylen /= 2;
            } else {
                ylen /= 2;
                ylen++;
            }
            cnt++;
        }

        int temp = cnt;
        cnt = 0;
        xlen = xlen0, ylen = ylen0;
        if (ylen - y <= y - 1) {
            ylen = ylen - y + 1;
        } else {
            ylen = y - 1 + 1;
        }
        cnt++;
        while (xlen > 1) {
            if (xlen % 2 == 0) {
                xlen /= 2;
            } else {
                xlen /= 2;
                xlen++;
            }
            cnt++;
        }
        while (ylen > 1) {
            if (ylen % 2 == 0) {
                ylen /= 2;
            } else {
                ylen /= 2;
                ylen++;
            }
            cnt++;
        }

        if (cnt <= temp) {
            cout << cnt << endl;
        } else {
            cout << temp << endl;
        }
    }
    return 0;
}