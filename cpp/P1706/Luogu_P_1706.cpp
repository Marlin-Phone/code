// https://www.luogu.com.cn/problem/P1706
#include <bits/stdc++.h>
using namespace std;

#define IOS                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);                                                                \
    cout.tie(0);
#define endl '\n'

const int N = 10;
int n;
bool st[N];
int arr[N];

void dfs(int x) {
    if (x > n) {
        for (int i = 1; i <= n; i++) {
            cout << "    " << arr[i];
        }
        cout << endl;
        return;
    }

    // 按照字典序(选中位置, 排序数字)
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            st[i] = true;
            arr[x] = i;
            dfs(x + 1);
            st[i] = false;
            arr[x] = 0;
        }
    }
    // 未按照字典序(选中数字, 排序位置)
    // for (int i = 1; i <= n; i++) {
    //     if (!st[i]) {
    //         st[i] = true;
    //         arr[i] = x;
    //         dfs(x + 1);
    //         st[i] = false;
    //         arr[i] = 0;
    //     }
    // }
}

int main() {
    IOS;
    cin >> n;
    dfs(1);
    return 0;
}