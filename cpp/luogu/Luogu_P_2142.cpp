// https://www.luogu.com.cn/problem/P2142
// 高精度减法
#include <bits/stdc++.h>
using namespace std;

const int N = 10100;
string sa, sb;
int la, lb;
int A[N], B[N], C[N];
int flag = 0;

int main() {
    cin >> sa >> sb;
    if (sb.length() > sa.length()) {
        swap(sa, sb);
        flag = 1;
    }
    if (sb.length() == sa.length() && sb > sa) {
        swap(sa, sb);
        flag = 1;
    }
    la = sa.length(), lb = sb.length();
    for (int i = 0; i < la; i++) {
        A[i] = sa[la - 1 - i] - '0';
    }
    for (int i = 0; i < lb; i++) {
        B[i] = sb[lb - 1 - i] - '0';
    }

    for (int i = 0; i < max(la, lb); i++) {
        if (A[i] - B[i] < 0) {
            A[i] += 10;
            A[i + 1]--;
        }
        C[i] = A[i] - B[i];
    }

    while (C[la] == 0 && la > 0) {
        la--;
    }

    if (flag == 1) {
        cout << "-";
    }
    for (int i = la; i >= 0; i--) {
        // cout << "i = " << i << endl;
        cout << C[i];
    }
}