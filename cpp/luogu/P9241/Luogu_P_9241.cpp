// https://luogu.com.cn/problem/P9241
// 排列型枚举 DFS 模拟
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 20;
int T;
int n;
int t[N], d[N], l[N];
int st[N], arr[N];
int flag = 0;
int maxend = -1;

void dfs(int x) { // 排列型枚举
    if (flag) {
        return;
    }
    if (x > n) {
        int plain;
        int now = 0;
        for (int i = 1; i <= n; i++) {
            plain = arr[i];
            if (t[plain] + d[plain] >= now &&
                t[plain] <= now) { // 起飞+等待>=now&&起飞<=now
                now += l[plain];
            } else if (t[plain] > now) {
                now = t[plain] + l[plain];
            } else {
                return; // 剪枝
            }
            // cout << "plain = " << plain << endl;
            // cout << "now = " << now << endl;
        }

        flag = 1;

        return;
    }
    // if (x > n) {
    //     int now = 0;
    //     for (int i = 1; i <= n; i++) {
    //         int p = arr[i];
    //         // 当前飞机的最早可降落时间 = max(now, t[p])
    //         int earliest_start = max(now, t[p]);

    //         // 如果最早可降落时间超过时间窗
    //         if (earliest_start > t[p] + d[p])
    //             return; // 直接剪枝

    //         // 更新当前时间为降落结束时间
    //         now = earliest_start + l[p];
    //     }
    //     flag = 1; // 找到可行解
    //     return;
    // }

    for (int i = 1; i <= n && flag == 0; i++) {
        if (st[i] == 1) {
            continue;
        }

        arr[x] = i;
        st[i] = 1;
        dfs(x + 1);
        arr[x] = 0; // 回溯
        st[i] = 0;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        memset(st, 0, sizeof(st));
        memset(arr, 0, sizeof(st));
        flag = 0;

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> t[i] >> d[i] >> l[i];
        }

        dfs(1);
        if (flag == 1) {
            cout << "YES" << endl;
        } else if (flag == 0) {
            cout << "NO" << endl;
        }
    }

    return 0;
}