// https://www.luogu.com.cn/problem/P2089
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);

const int N = 5e3 + 10;
int n;
int ans = 0;
int arr[15];
int mem[60000][15];

void dfs(int x, int sum) { // x 表示当前的位数
    if (sum > n)           // 剪枝
        return;

    if (x > 10) {
        if (sum == n) {
            ans++;
            for (int i = 1; i <= 10; i++) {
                mem[ans][i] = arr[i];
            }
        }
        return;
    }

    for (int i = 1; i <= 3; i++) {
        arr[x] = i;
        dfs(x + 1, sum + i);
        arr[x] = 0; // 回溯
    }
}

int main() {
    cin >> n; // 3^10 = 59049;
    if (n < 10 || n > 30) {
        cout << 0;
        return 0;
    }
    dfs(1, 0);
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}