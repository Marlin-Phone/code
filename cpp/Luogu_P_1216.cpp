#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n;
int g[N][N];
int mem[N][N];
int f[N][N];

int dfs(int x, int y) {
    if (mem[x][y])
        return mem[x][y];
    int sum = 0;
    if (x > n || y > n)
        sum = 0;
    else
        sum = max(dfs(x + 1, y), dfs(x + 1, y + 1)) + g[x][y];

    mem[x][y] = sum;
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }

    //    cout << dfs(1, 1) << endl;

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + g[i][j];
        }
    }
    cout << f[1][1] << endl;

    return 0;
}