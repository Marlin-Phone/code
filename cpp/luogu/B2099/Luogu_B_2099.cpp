// https://www.luogu.com.cn/problem/B2099
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int A[N][N];
int temp[N];
int m, n;

int main() {

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> A[i][j];
        }
    }
    cin >> m >> n;
    for (int i = 1; i <= 5; i++) {
        temp[i] = A[m][i];
        A[m][i] = A[n][i];
        A[n][i] = temp[i];
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}