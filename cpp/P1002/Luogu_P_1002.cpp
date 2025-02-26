// https://www.luogu.com.cn/problem/P1002
#include <cstring>
#include <iostream>
using namespace std;

const int N = 30;
int x0, y0, x1, y1; // 0为B点 1为马
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int cnt = 0;
int dx1[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
int dy1[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
long long mem[N][N];
long long dp[N][N];

bool house(int x, int y) {
    for (int i = 0; i <= 8; i++) {
        int a = x1 + dx1[i];
        int b = y1 + dy1[i];
        if (x == a && y == b) {
            return true;
        }
    }

    return false;
}
long long dfs(int x, int y) {
    if (mem[x][y] != -1) {
        return mem[x][y];
    }
    if (x > x0 || y > y0 || x < 0 || y < 0) {
        return mem[x][y] = 0;
    }
    if (house(x, y)) {
        return mem[x][y] = 0;
    }
    if (x == x0 && y == y0) {
        return mem[x][y] = 1;
    }

    return mem[x][y] = dfs(x, y + 1) + dfs(x + 1, y);
}
int main() {
    memset(mem, -1, sizeof(mem));
    cin >> x0 >> y0 >> x1 >> y1;
    // cout << dfs(0, 0);

    dp[x0][y0] = 1;
    for (int i = x0; i >= 0; i--) {
        for (int j = y0; j >= 0; j--) {
            if (i == x0 && j == y0) {
                continue;
            }
            if (house(i, j)) {
                continue;
            }
            dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
        }
    }

    cout << dp[0][0];

    return 0;
}