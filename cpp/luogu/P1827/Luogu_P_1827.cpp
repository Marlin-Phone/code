// https://luogu.com.cn/problem/P1827
// 二叉树
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// const int N =
string inOrder, preOrder;

string buildPostOrder(string &in, string &pre) {
    if (in.empty()) {
        return "";
    }

    char root = pre.front();
    int rootIndex = in.find(root);

    string leftIn = in.substr(0, rootIndex);
    string rightIn = in.substr(rootIndex + 1);

    int leftLen = leftIn.size();
    string leftPre = pre.substr(1, leftLen);
    string rightPre = pre.substr(1 + leftLen);

    string leftPost = buildPostOrder(leftIn, leftPre);
    string rightPost = buildPostOrder(rightIn, rightPre);

    return leftPost + rightPost + root;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> inOrder >> preOrder;

    string postOrder = buildPostOrder(inOrder, preOrder);

    cout << postOrder;

    return 0;
}