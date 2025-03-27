// 组合
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 30;
int n, k;
int arr[N];

void dfs(int x, int start) {
    if (x > k) {
        for (int i = 1; i <= k; i++) {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; i++) {
        if (n - i + 1 < k - x + 1) {
            break;
        }
        arr[x] = i;
        dfs(x + 1, i + 1);
        arr[x] = 0;
    }
}

signed main() {
    cin >> n >> k;
    dfs(1, 1);
}