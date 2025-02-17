// https://www.luogu.com.cn/problem/P1596
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl "\n"

const int N0 = 1e2 + 10;
int N, M;
char g[N0][N0];
bool st[N0][N0];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ans = 0;

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int a = x + dx[i];
            int b = y + dy[j];

            if (a < 0 || a >= N || b < 0 || b >= M)
                continue;
            if (st[a][b] == true)
                continue;
            if (g[a][b] == '.')
                continue;

            st[a][b] = true;
            dfs(a, b);
        }
    }

    //
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