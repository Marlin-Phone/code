// https://luogu.com.cn/problem/P4715
// 位运算 二叉树 孩子表示法
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1024;
int n;
int nums[N];
struct {
    int val, num;
} a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int t = 1;
    for (int i = (1 << n); i < (1 << (n + 1)); i++) {
        cin >> a[i].val;
        a[i].num = t;
        t++;
    }
    for (int i = (1 << n) - 1; i >= 1; i--) {
        if (a[i * 2].val > a[i * 2 + 1].val) {
            a[i] = a[i * 2];
        } else {
            a[i] = a[i * 2 + 1];
        }
    }

    if (a[2].val < a[3].val) {
        cout << a[2].num;
    } else {
        cout << a[3].num;
    }

    return 0;
}