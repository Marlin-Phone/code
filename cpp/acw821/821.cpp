#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int f[N];

int main() {
    cin >> n;

    f[1] = 1, f[2] = 2;
    if (n == 1 || n == 2) {
        cout << f[n] << endl;
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2]; // 这个递推公式也就是 dfs 的向下递归公式
    }

    cout << f[n] << endl;

    return 0;
}