// https://www.luogu.com.cn/problem/P1451
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);

const int N = 110;
int n, m;
char g[N][N];
bool st[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 0 || a >= n || b < 0 || b >= m)
            continue;
        if (g[a][b] == '0')
            continue;
        if (st[a][b] == true)
            continue;

        st[a][b] = true;
        dfs(a, b);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '0' && st[i][j] == false) {
                st[i][j] = true;
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}