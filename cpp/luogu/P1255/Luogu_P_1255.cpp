// https://www.luogu.com.cn/problem/P1255
#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
int n;
int a[N], b[N], c[N], lc = 1;

int main() {
    cin >> n;
    // int a = 1, b = 1, c;
    a[1] = 1;
    b[1] = 2;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n == 2) {
        cout << 2;
        return 0;
    }
    // c = a + b;
    for (int i = 3; i <= n; i++) {
        memset(c, 0, sizeof(c));
        for (int j = 1; j <= lc; j++) {
            c[j] += a[j] + b[j];
            c[j + 1] = c[j] / 10;
            c[j] %= 10;
        }
        if (c[lc + 1] > 0) {
            lc++;
        }
        // swap(a, b);
        // swap(b, c);
        // a = b;
        // b = c;
        for (int j = 1; j <= lc; j++) {
            a[j] = b[j];
        }
        for (int j = 1; j <= lc; j++) {
            b[j] = c[j];
        }
    }

    // cout << c;
    for (int i = lc; i >= 1; i--) {
        cout << c[i];
    }

    return 0;
}