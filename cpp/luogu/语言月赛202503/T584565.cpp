#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, m; // 行和列
int g[N][N];
int x, y; // x为g[i][j], y为旁边的数.
int cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    cin >> x >> y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == x) {
                for (int k = 0; k < 4; k++) {
                    int a = i + dx[k];
                    int b = j + dy[k];

                    if (a < 1 || b < 1 || a > n || b > m)
                        continue;

                    if (g[a][b] == y) {
                        cnt++;
                        // cout << "(i, j) = " << "(" << i << ", " << j << ")"
                        //      << endl;
                        // cout << "g[a][b] = " << g[a][b] << endl;
                        // cout << "x = " << x << endl;
                        // cout << "(a, b) = " << a << ", " << b << endl;
                        // cout << "y = " << y << endl;
                        // cout << "i = " << i << endl;
                        // cout << "j = " << j << endl;
                        // cout << endl;
                        break;
                    }
                }
            }
        }
    }

    cout << cnt;

    return 0;
}