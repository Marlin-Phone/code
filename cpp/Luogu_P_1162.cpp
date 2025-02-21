// https://www.luogu.com.cn/problem/P1162
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 40;
int n;
int g[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int st[N][N] = {0};
queue<pair<int, int>> q;

void bfs(int x, int y) {
    q.push({x, y});
    st[x][y] = 2;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a < 0 || a >= n + 2 || b < 0 || b >= n + 2)
                continue;
            if (g[a][b] == 1 || st[a][b] == 2)
                continue;

            st[a][b] = 2;
            q.push({a, b});
        }
    }
    return;
}
void dfs(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 0 || a >= n + 2 || b < 0 || b >= n + 2)
            continue;
        if (g[a][b] == 1) {
            st[a][b] = 1;
            continue;
        }
        if (st[a][b] == 1 || st[a][b] == 2)
            continue;

        st[a][b] = 2;
        dfs(a, b);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 1) {
                st[i][j] = 1;
            }
        }
    }

    // dfs(0, 0);
    bfs(0, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i][j] == 2) {
                cout << 0 << " ";
            } else if (st[i][j] == 0) {
                cout << 2 << " ";
            } else if (st[i][j] == 1) {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}