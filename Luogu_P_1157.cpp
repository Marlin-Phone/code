// https://www.luogu.com.cn/problem/P1157
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

int n, r; // n个元素中选r个
const int N = 25;
bool st[N];
int arr[N];

void dfs(int x, int start) {
    if (x > r) {
        for (int i = 1; i <= r; i++) {
            cout << setw(3) << arr[i];
        }
        cout << endl;
        return; // 递归出口
    }

    for (int i = start; i <= n; i++) {
        st[i] = true;
        arr[x] = i;
        dfs(x + 1, i + 1);
        st[i] = false;
    }
}
int main() {
    IOS;
    cin >> n >> r;
    dfs(1, 1);
    return 0;
}