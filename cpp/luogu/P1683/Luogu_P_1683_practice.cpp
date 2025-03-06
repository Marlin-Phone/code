#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int N = 30;
int W, H;     // H行 W列
char g[N][N]; // 图
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool st[N][N];
int ans = 0;

void dfs(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 0 || a >= H || b < 0 || b >= W)
            continue;
        if (g[a][b] == '#')
            continue;
        if (st[a][b] == true)
            continue;

        ans++;
        st[a][b] = true;
        dfs(a, b);
    }
}
int main() {
    IOS;

    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (g[i][j] == '@') {
                st[i][j] = true;
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}