// https://www.luogu.com.cn/problem/P1067
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n; // 多项式次数
int a; // 多项式系数

int main() {
    cin >> n;
    for (int i = n; i >= 0; i--) {
        cin >> a;
        if (a != 0) {
            if (i < n && a > 0) {
                cout << "+";
            }
            if (abs(a) > 1 || i == 0) {
                cout << a;
            }
            if (a == -1 && i) {
                cout << "-";
            }
            if (i > 0) {
                cout << "x";
            }
            if (i > 1) {
                cout << "^" << i;
            }

        } else {
        }
    }

    return 0;
}