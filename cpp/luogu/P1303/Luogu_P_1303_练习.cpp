// https://www.luogu.com.cn/problem/P1303
#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 10;
string sa, sb;
int A[N], B[N], C[N];
int la, lb, lc;

int main() {
    cin >> sa >> sb;
    la = sa.length(), lb = sb.length();

    for (int i = 0; i < la; i++) {
        A[la - i] = sa[i] - '0';
    }
    for (int i = 0; i < lb; i++) {
        B[lb - i] = sb[i] - '0';
    }

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            C[i + j - 1] += A[i] * B[j];
            C[i + j] += C[i + j - 1] / 10;
            C[i + j - 1] %= 10;
        }
    }

    lc = la + lb;
    while (C[lc] == 0 && lc > 1) {
        lc--;
    }

    for (int i = lc; i >= 1; i--) {
        // cout << "i = " << i << endl;
        cout << C[i];
    }

    return 0;
}