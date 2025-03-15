// https://www.luogu.com.cn/problem/P1164
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
int a[N];
int mem[10010][N];

int dfs(int men, int x) { // men钱 第x个菜
    if (men < 0)
        return 0;
    if (x > n) {
        if (men == 0) {
            return mem[men][x] = 1;
        }
        return 0;
    }
    if (mem[men][x]) {
        return mem[men][x];
    }

    return mem[men][x] = dfs(men, x + 1) + dfs(men - a[x], x + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << dfs(m, 1);

    return 0;
}