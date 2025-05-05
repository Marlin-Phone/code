// https://luogu.com.cn/problem/P1030
// 二叉树 后序序列 中序序列 先序序列
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
string inorder, postorder;

string buildpreorder(string &in, string &post) {
    if (post.empty()) {
        return "";
    }

    char root = post.back();
    int rootIndex = in.find(root);

    string leftIn = in.substr(0, rootIndex);   // 0 到 rootIndex - 1;
    string rightIn = in.substr(rootIndex + 1); // rootIndex + 1 到 end();

    int leftLen = leftIn.size();
    string leftPost = post.substr(0, leftLen);
    string rightPost = post.substr(leftLen, post.size() - 1 - leftLen);

    string leftPre = buildpreorder(leftIn, leftPost);
    string rightPre = buildpreorder(rightIn, rightPost);

    return root + leftPre + rightPre;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> inorder >> postorder;

    string ans = buildpreorder(inorder, postorder);

    cout << ans;

    return 0;
}