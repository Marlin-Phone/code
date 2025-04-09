// https://luogu.com.cn/problem/P
// DFS | 对角线
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 100;
int n;
int cnt;
int m1[N]; // 列
int m2[N]; // 顺对角线
int m3[N]; // 逆对角线
int ans[N];

void func(int x, int y, int k) {
    ans[x] = y; // 第x行的y坐标(x, y)
    m1[y] = k;
    m2[x - y + n] = k;
    m3[x + y] = k;
}
void dfs(int x) {
    if (x > n) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (m1[j] || m2[x - j + n] || m3[x + j]) {
            continue;
        }
        func(x, j, 1); // 表示来过
        dfs(x + 1);
        func(x, j, 0); // 回溯
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dfs(1);
    cout << cnt;

    return 0;
}