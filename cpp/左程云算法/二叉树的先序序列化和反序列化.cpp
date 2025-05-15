#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
        : val(val), left(left), right(right) {}
};
string ans, str;
int idx = 0;

void dfs(TreeNode *root) {
    if (root == nullptr) {
        ans += "#,";
        return;
    }

    ans += to_string(root->val) + ',';
    dfs(root->left);
    dfs(root->right);
}
TreeNode *redfs(vector<string> &tokens) {
    string temp = tokens[idx++];
    if (temp == "#") {
        return nullptr;
    }
    TreeNode *head = new TreeNode(stoi(temp));
    head->left = redfs(tokens);
    head->right = redfs(tokens);

    return head;
}
int main() {
    string token;
    vector<string> tokens;

    cin >> str;
    istringstream iss(str);
    while (getline(iss, token, ',')) {
        tokens.push_back(token);
    }
    TreeNode *head = redfs(tokens);
    dfs(head);
    ans.pop_back();
    cout << ans << endl;

    return 0;
}