#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int R, C;
char g[N][N];
bool st[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 1 || b < 1 || a > R || b > C)
            continue;
        if (st[a][b] == true)
            continue;
        if (g[a][b] == '.')
            continue;

        st[a][b] = true;
        dfs(a, b);
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if ((g[i][j] == '.' && g[i + 1][j] == '#' && g[i][j + 1] == '#' &&
                 g[i + 1][j + 1] == '#') ||
                (g[i][j] == '#' && g[i + 1][j] == '.' && g[i][j + 1] == '#' &&
                 g[i + 1][j + 1] == '#') ||
                (g[i][j] == '#' && g[i + 1][j] == '#' && g[i][j + 1] == '.' &&
                 g[i + 1][j + 1] == '#') ||
                (g[i][j] == '#' && g[i + 1][j] == '#' && g[i][j + 1] == '#' &&
                 g[i + 1][j + 1] == '.')) {
                cout << "Bad placement." << endl;
                return 0;
            }
            if (st[i][j] == false && g[i][j] == '#') {
                st[i][j] = true;
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << "There are " << cnt << " ships.";

    return 0;
}