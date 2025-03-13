// https://www.luogu.com.cn/problem/P1605
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;        // 长
int m;        // 宽
int t;        // 障碍总数
int sx, sy;   // 起点坐标
int fx, fy;   // 终点坐标
int st[N][N]; // 0为可达, 1为不可达
int xt, yt;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
long long ans = 0;
queue<pair<int, int>> que;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a < 1 || b < 1 || a > n || b > m)
            continue;
        if (st[a][b] == 1)
            continue;

        st[a][b] = 1;
        dfs(a, b);
        st[a][b] = 0;
    }
}
// void bfs(int x, int y){ // 本题基本不可行(状态过多,无法记录)
//     que.push({x, y});

//     while(!que.empty()){
//         auto t = que.front();
//         que.pop();

//         for (int i = 0; i < 4; i++){
//             int a = t.first + dx[i];
//             int b = t.second + dy[i];

//             if(st[a][b] == 1)
//                 continue;
//             if(a < 1 || b < 1 || a > n || b > m)
//                 continue;

//             st[a][b] = 1;

//         }
//     }
// }
int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    for (int i = 1; i <= t; i++) {
        cin >> xt >> yt;
        st[xt][yt] = 1;
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << st[i][j];
    //     }
    //     cout << endl;
    // }

    st[sx][sy] = 1; // 标记起点
    dfs(sx, sy);

    cout << ans;

    return 0;
}