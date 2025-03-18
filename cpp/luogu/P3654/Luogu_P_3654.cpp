// https://www.luogu.com.cn/problem/P3654
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int r, c, k;
char g[N][N];
int ans = 0;
bool flag = true;

void check(int x, int y) {
    flag = true;
    int a = x + k - 1;
    int b = y;
    if (a <= r) {
        for (int i = x, j = y; i <= a; i++) {
            if (g[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            // cout << "in_x:x = " << x << " y = " << y << endl;
            ans++;
        }
    }

    flag = true;
    a = x;
    b = y + k - 1;
    if (b <= c) {
        for (int i = x, j = y; j <= b; j++) {
            if (g[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            // cout << "in_y:x = " << x << " y = " << y << endl;
            ans++;
        }
    }
}
int main() {
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (g[i][j] == '.') {
                check(i, j);
            }
        }
    }

    if (k == 1) {
        ans = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (g[i][j] == '.') {
                    ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}