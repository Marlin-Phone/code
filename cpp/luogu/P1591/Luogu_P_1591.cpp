// https://luogu.com.cn/problem/P1591
#include <bits/stdc++.h>
using namespace std;

const int N0 = 3e3;
const int N = 3e3 - 10;
int t;
int n; // 阶乘n
int a; // 数码a
int A[N0];
int cnt = 0;

void cheng(int x) {
    int carry = 0;
    for (int i = 1; i < N - 1; i++) {
        A[i] = A[i] * x + carry;
        carry = A[i] / 10;
        A[i] %= 10;
    }
}
int main() {
    cin >> t;
    while (t--) {
        memset(A, 0, sizeof(A));
        A[1] = 1;
        cin >> n >> a;
        for (int i = 1; i <= n; i++) {
            cheng(i);
        }

        int index = N - 1;
        cnt = 0;
        while (A[index] == 0 && index > 1) {
            index--;
        }
        for (int i = index; i >= 1; i--) {
            if (A[i] == a) {
                cnt++;
            }
            // cout << A[i];
        }

        // cout << endl;
        cout << cnt << endl;
    }

    return 0;
}