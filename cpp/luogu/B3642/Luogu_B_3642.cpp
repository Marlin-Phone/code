// https://luogu.com.cn/problem/B3642
// 树型数据结构 二叉树
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e6 + 10;
int T = 1;
int n;
struct TreeNode {
    int idx;
    int left;
    int right;
} TreeNode[N];

void predfs(int idx) {
    if (idx == 0) {
        return;
    }
    cout << idx << " ";
    predfs(TreeNode[idx].left);
    predfs(TreeNode[idx].right);
}
void orderdfs(int idx) {
    if (idx == 0) {
        return;
    }
    orderdfs(TreeNode[idx].left);
    cout << idx << " ";
    orderdfs(TreeNode[idx].right);
}
void redfs(int idx) {
    if (idx == 0) {
        return;
    }
    redfs(TreeNode[idx].left);
    redfs(TreeNode[idx].right);
    cout << idx << " ";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int left, right;
            cin >> left >> right;
            TreeNode[i].left = left, TreeNode[i].right = right;
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << "i = " << i << " ";
        //     cout << TreeNode[i].left << " " << TreeNode[i].right << endl;
        // }
        predfs(1);
        cout << endl;
        orderdfs(1);
        cout << endl;
        redfs(1);
    }
    return 0;
}