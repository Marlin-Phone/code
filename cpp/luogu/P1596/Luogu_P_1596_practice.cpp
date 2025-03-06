#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

const int N0 = 110;
int N, M;        // N 行 M列
char g[N0][N0];  // 图
bool st[N0][N0]; // 状态
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int ans = 0;

void dfs(int x, int y) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a < 0 || a >= N || b < 0 || b >= M)
                continue;
            if (g[a][b] == '.')
                continue;
            if (st[a][b] == true)
                continue;

            st[a][b] = true;
            dfs(a, b);
        }
    }
}
int main() {
    IOS;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (g[i][j] == 'W' && st[i][j] == false) {
                st[i][j] = true;
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}