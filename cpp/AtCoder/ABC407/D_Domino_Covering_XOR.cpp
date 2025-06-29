// https://luogu.com.cn/problem/P
// DFS 回溯 异或的性质
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

const int N = 100;
int T = 1;
int H, W;
int g[N][N];
int st[N][N];
int ans;
int now;

void dfs(int x, int y) {
    if (x == H && y == W) {
        ans = max(now, ans);
        return;
    }

    if (st[x][y] == 0) {
        // 向右
        if (y + 1 <= W && st[x][y + 1] == 0) {
            now ^= (g[x][y] ^ g[x][y + 1]);
            st[x][y + 1] = 1;

            if (y + 1 == W + 1) {
                dfs(x + 1, 1);
            } else {
                dfs(x, y + 1);
            }
            now ^= (g[x][y] ^ g[x][y + 1]);
            st[x][y + 1] = 0;
        }

        // 向下
        if (x + 1 <= H && st[x + 1][y] == 0) {
            now ^= (g[x][y] ^ g[x + 1][y]);
            st[x + 1][y] = 1;
            if (y + 1 == W + 1) {
                dfs(x + 1, 1);
            } else {
                dfs(x, y + 1);
            }
            now ^= (g[x][y] ^ g[x + 1][y]);
            st[x + 1][y] = 0;
        }
    }

    // 都不选的情况
    if (y + 1 == W + 1) {
        dfs(x + 1, 1);
    } else {
        dfs(x, y + 1);
    }
}
// int getmaxxor() {
//     int maxxor = 0;
//     for (int i = 1; i <= H; i++) {
//         for (int j = 1; j <= W; j++) {
//             for (int k = 0; k < 2; k++) {
//                 int a = i + dx[k];
//                 int b = j + dy[k];
//                 if (st[i][j] == 1 || st[a][b] == 1) {
//                     continue;
//                 }
//                 int fxors = g[i][j] ^ g[a][b];
//                 if (fxors > maxxor) {
//                     maxxor = fxors;
//                     while (!q.empty()) {
//                         q.pop();
//                     }
//                     q.push({i, j});
//                     q.push({a, b});
//                 }
//             }
//         }
//     }
//     int temp1 = q.front().first;
//     int temp2 = q.front().second;
//     st[temp1][temp2] = 1;
//     q.pop();
//     temp1 = q.front().first;
//     temp2 = q.front().second;
//     st[temp1][temp2] = 1;

//     return maxxor;
// }
void solve() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> g[i][j];
            now ^= g[i][j];
        }
    }
    dfs(1, 1);
    cout << ans;

    // int sum;
    // while (1) {
    //     int temp = getmaxxor();
    //     cout << temp << endl;
    //     if (temp == 0) {
    //         break;
    //     } else {
    //         sum += temp;
    //     }
    //     continue;
    // }
    // for (int i = 1; i <= H; i++) {
    //     for (int j = 1; j <= W; j++) {
    //         cout << st[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}