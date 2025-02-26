#include <bits/stdc++.h>
using namespace std;

const int N = 250;
int n;
int r[N][N]; // r[i][j] 表示从 i 到 j 的租金
int mem[N];

int getmin(int x) { // 出租站i
    int minnum = 1e8;
    for (int i = 1; r[x][i] != 0; i++) {
        minnum = min(minnum, r[x][i]);
    }
    return minnum;
}
int dfs(int x) { // 出租站i
    if (mem[x])
        return mem[x];
    if (x == n)
        mem[x] = 0;

    mem[x] = dfs(x + 1) + getmin(x);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cin >> r[i][j];
        }
    }

    cout << dfs(1);

    return 0;
}