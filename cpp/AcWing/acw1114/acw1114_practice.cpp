#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int N = 10;
int n, k;     // n * n的棋盘 k个棋子
char g[N][N]; // 存地图
bool st[N];   // 存状态
int ans = 0;

void dfs(int x, int cnt) { // x 表示当前的行数 cnt 记录当前放了多少个棋子
    if (cnt == k) {
        ans++;
        return;
    }
    if (x == n) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (st[i] == false && g[x][i] == '#') {
            st[i] = true;
            dfs(x + 1, cnt + 1);
            st[i] = false;
        }
    }
    dfs(x + 1, cnt); // 强行访问下一行
}
int main() {
    IOS;

    while (cin >> n >> k && n > 0 && k > 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }

        ans = 0;

        dfs(0, 0);

        cout << ans << endl;
    }

    return 0;
}