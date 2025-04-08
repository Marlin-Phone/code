// https://luogu.com.cn/problem/P1036
// 质数 组合型枚举 DFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 30;
int n, k;
int X[N];
int cnt = 0;
int arr[N];

bool check(int num) {
    if (num == 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    for (int i = 2; i <= sqrt(num) + 1; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
void dfs(int x, int start) {
    if (x > k) {
        int num = 0;
        int index;
        for (int i = 1; i <= k; i++) {
            index = arr[i];
            num += X[index];
        }
        if (check(num) == true) {
            cnt++;
        }
        return;
    }

    for (int i = start; i <= n; i++) {
        arr[x] = i;
        dfs(x + 1, i + 1);
        arr[x] = 0; // 回溯
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }

    dfs(1, 1);

    cout << cnt;

    return 0;
}