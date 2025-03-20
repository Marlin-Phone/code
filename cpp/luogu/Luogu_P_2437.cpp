#include <bits/stdc++.h>
using namespace std;

int m, n;

int dfs(int x) { // x 表示数字
    if (x ==)

        if (x % 2 == 1) {
            dfs(x + 1);
            dfs(x + 2);
        } else {
            dfs(x + 1);
            dfs(x + 2);
        }
}
int main() {
    cin >> m >> n;
    dfs(m);

    return 0;
}