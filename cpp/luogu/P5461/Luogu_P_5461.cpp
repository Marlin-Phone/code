// https://www.luogu.com.cn/problem/P5461
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1030;
bool st[N][N];
int n;

void fenzhi(int x, int y, int n) {
    if (n < 1) {
        return;
    }
    if (n > 0) {
        for (int i = x; i < n / 2 + x; i++) {
            for (int j = y; j < n / 2 + y; j++) {
                st[i][j] = 0;
            }
        }
    }

    fenzhi(x + (n / 2), y, n / 2);
    fenzhi(x, y + (n / 2), n / 2);
    fenzhi(x + (n / 2), y + (n / 2), n / 2);
}

int main() {
    memset(st, 1, sizeof(st));

    cin >> n;

    fenzhi(0, 0, pow(2, n));

    for (int i = 0; i < pow(2, n); i++) {
        for (int j = 0; j < pow(2, n); j++) {
            cout << st[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}