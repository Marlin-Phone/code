// https://luogu.com.cn/problem/P10387
// 枚举 全体训练的次数
// 重点是 **记录需要训练i次的士兵一次训练所需的金币之和**
// 可把O(n^2)优化到O(n)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;
int n; // 士兵数量
int s; // 进行一次组团训练所需的金币数
// int p[N]; // 第i名士兵进行一次训练的金币
// int c[N]; // 成为顶尖战士所需的训练次数
struct node {
    int p; // 一次训练的金币
    int c; // 训练次数
} node[N];
int sump = 0; // 每个士兵单独训练的总金币
int ans = 0;
int cnt[N];

signed main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].p >> node[i].c;
        sump += node[i].p;

        // *需要训练i次的士兵一次训练所需的金币之和.
        cnt[node[i].c] += node[i].p;
    }

    // 优化前代码 O(n^2)
    // while (s < sump) {
    //     ans += s;
    //     for (int i = 1; i <= n; i++) {
    //         if (node[i].c > 0) {
    //             node[i].c--;
    //             if (node[i].c <= 0) {
    //                 sump -= node[i].p;
    //             }
    //         }
    //     }
    // }

    int index;
    for (int i = 1; i <= 1e6; i++) {
        if (s > sump) {
            break;
        }
        ans += s;
        sump -= cnt[i];
        index = i;
    }

    // s >= sump;
    // for (int i = 1; i <= n; i++) {
    //     ans += node[i].c * node[i].p;
    // }

    for (int i = index + 1; i <= 1e6; i++) {
        ans += cnt[i] * (i - index);
        // if (cnt[i] != 0) {
        //     cout << cnt[i] << endl;
        // }
    }
    cout << ans;

    return 0;
}