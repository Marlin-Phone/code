// https://www.luogu.com.cn/problem/P1088
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int N = 1e4 + 10;
int n, m;
int num[N];
int arr[N];
bool st[N];
int res = 0;

void dfs(int x) {
    if (x > n) {
        // for (int i = 1; i <= n; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        res++;
        if (res == m + 1) {
            for (int i = 1; i <= n; i++) {
                cout << arr[i] << " ";
            }
            exit(0); // 剪枝
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!res) {
            i = num[x];
        }
        if (!st[i]) {
            st[i] = true;
            arr[x] = i;
            dfs(x + 1);
            st[i] = false; // 回溯
            arr[x] = 0;
        }
    }
}
int main() {
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    dfs(1);

    return 0;
}