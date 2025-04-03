// https://www.luogu.com.cn/problem/P2615
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int n; // 幻方的大小
int nums[N][N];

int main() {
    cin >> n;
    nums[1][(n + 1) / 2] = 1;
    int x_km1 = 1, y_km1 = (n + 1) / 2;
    int x_k, y_k;
    for (int k = 2; k <= n * n; k++) {
        if (x_km1 == 1 && y_km1 != n) {
            x_k = n, y_k = y_km1 + 1;
            // cout << "a: " << x_k << " " << y_k << " " << k << endl;
        } else if (y_km1 == n && x_km1 != 1) {
            y_k = 1, x_k = x_km1 - 1;
            // cout << "b: " << x_k << " " << y_k << " " << k << endl;
        } else if (x_km1 == 1 && y_km1 == n) {
            x_k = x_km1 + 1, y_k = y_km1;
            // cout << "c: " << x_k << " " << y_k << " " << k << endl;
        } else if (x_km1 != 1 && y_km1 != n) {
            if (nums[x_km1 - 1][y_km1 + 1] == 0) {
                x_k = x_km1 - 1, y_k = y_km1 + 1;
                // cout << "d: " << x_k << " " << y_k << " " << k << endl;
            } else {
                x_k = x_km1 + 1, y_k = y_km1;
                // cout << "e: " << x_k << " " << y_k << " " << k << endl;
            }
        }
        nums[x_k][y_k] = k;
        x_km1 = x_k, y_km1 = y_k;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}