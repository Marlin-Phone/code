// https://luogu.com.cn/problem/P1305
// 二叉树 先序遍历
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

struct node {
    char l, r;
} tree[150];

// const int N =
int n;

void dfs(char pos) {
    cout << pos;
    if (tree[pos].l != '*') {
        dfs(tree[pos].l);
    }
    if (tree[pos].r != '*') {
        dfs(tree[pos].r);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char a, l, r, bg;
    cin >> n;
    cin >> bg >> l >> r;
    tree[bg].l = l;
    tree[bg].r = r;
    for (int i = 1; i < n; i++) {
        cin >> a >> l >> r;
        tree[a].l = l;
        tree[a].r = r;
    }

    dfs(bg);

    return 0;
}