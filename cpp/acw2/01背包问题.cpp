#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;       // n个物品,背包容量
int v[N], w[N]; // 体积,价值

int dfs(int x, int spV) { // 当前物品, 剩余体积
    if (x > n) {
        return 0;
    } else if (spV < v[x]) {
        return dfs(x + 1, spV);
    } else if (spV >= v[x]) {
        return max(dfs(x + 1, spV), dfs(x + 1, spV - v[x]) + w[x]);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    int res = dfs(1, m);
    cout << res << endl;

    return 0;
}