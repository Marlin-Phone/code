// https://luogu.com.cn/problem/P1162
// dfs 迷宫 洪水填充
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 40;
int n;
int g[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int st[N][N];

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 0 || b < 0 || a > n + 1 || b > n + 1) {
            continue;
        }
        if (g[a][b] == 1) {
            continue;
        }
        if (st[a][b] == 2) {
            continue;
        }

        st[a][b] = 2;
        dfs(a, b);
    }

    // return;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    dfs(0, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i][j] == 2) {
                cout << "0 ";
            } else if (g[i][j] == 1) {
                cout << "1 ";
            } else if (st[i][j] == 0) {
                cout << "2 ";
            }
        }
        cout << endl;
    }

    return 0;
}