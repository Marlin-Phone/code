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
int mem[N][N];

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
int dfs(int x, int y) {
    if (mem[x][y] != -1) {
        return mem[x][y];
    }
    if (x > x0 || y > y0) {
        return mem[x][y] = 0;
    }
    if (house(x, y)) {
        return mem[x][y] = 0;
    }
    if (x == x0 && y == y0) {
        return mem[x][y] = 1;
    }

    return mem[x][y] = dfs(x, y + 1) + dfs(x + 1, y);
    // for (int i = 0; i < 2; i++) {
    //     int a = x + dx[i];
    //     int b = y + dy[i];

    //     if (house(a, b) == true)
    //         continue;
    //     if (a > 6 || b > 6)
    //         continue;

    //     dfs(a, b);
    // }
}
int main() {
    memset(mem, -1, sizeof(mem));
    cin >> x0 >> y0 >> x1 >> y1;
    cout << dfs(0, 0);
    return 0;
}