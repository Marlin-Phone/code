#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n, m; // n 里面取 m个数
int st[N];
int arr[N];

void dfs(int x, int start) { // x为当前的位置, start为之后最小的位置
    if (x + n - start < m) { // 剪枝 如果把后面所有数都选上也不够m个
        return;
    }
    if (x > m) {
        for (int i = 1; i <= m; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    for (int i = start; i <= n; i++) {
        if (x > m /* || st[i] == 1*/) {
            continue;
        }
        arr[x] = i;
        // st[i] = 1; // 之后的数一定比这个数大, 不用判断该数是否用过
        dfs(x + 1, i + 1);
        arr[x] = 0;
        // st[i] = 0;
    }
}
int main() {
    cin >> n >> m;
    dfs(1, 1);

    return 0;
}