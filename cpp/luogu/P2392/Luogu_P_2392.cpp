// https://www.luogu.com.cn/problem/P2392
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int s[5];
int times[5][N];
int l, r;
int ans = 0;

int dfs(int x, int y) {
    if (y > s[x]) {
        return max(l, r);
    }
    l += times[x][y];
    int res1 = dfs(x, y + 1);
    l -= times[x][y];

    r += times[x][y];
    int res2 = dfs(x, y + 1);
    r -= times[x][y];

    return min(res1, res2);
}
int main() {
    for (int i = 1; i <= 4; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= s[i]; j++) {
            cin >> times[i][j];
        }
        l = 0, r = 0;
        ans += dfs(i, 1);
        // cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}