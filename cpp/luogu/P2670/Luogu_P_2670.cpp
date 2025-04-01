// https://www.luogu.com.cn/problem/P2670
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
char g[N][N];
int dx[10] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[10] = {0, 1, 1, 1, 0, -1, -1, -1};

int dfs(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 1 || b < 1 || a > n || b > n) {
            continue;
        }

        if (g[a][b] == '*') {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    int cnt;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '?') {
                cnt = dfs(i, j);
                g[i][j] = cnt + '0';
            }
            cout << g[i][j];
        }
        cout << endl;
    }

    return 0;
}