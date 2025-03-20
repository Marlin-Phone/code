// https://www.luogu.com.cn/problem/P5731
#include <bits/stdc++.h>
using namespace std;

int n;
int dx[4] = {0, 1, 0, -1}; // 右下左上
int dy[4] = {1, 0, -1, 0};
int num = 1;
int st[15][15];
int arr[15][15];

void dfs(int x, int y, int p) {
    if (num == n * n) {
        return;
    }

    int a = x + dx[p];
    int b = y + dy[p];

    if (st[a][b] == 1 || a < 1 || a > n || b < 1 || b > n) {
        int newp = (p + 1) % 4;
        dfs(x, y, newp);
        return;
    }

    st[a][b] = 1;
    num++;
    arr[a][b] = num;
    // cout << num << endl;
    dfs(a, b, p);
}
int main() {
    cin >> n;
    arr[1][1] = num;
    st[1][1] = 1;
    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}