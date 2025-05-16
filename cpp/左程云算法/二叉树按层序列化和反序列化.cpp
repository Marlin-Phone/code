#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val) {};
};
string str, token;
vector<string> tokens;
int idx = 0;
queue<TreeNode *> q;
string ans;

TreeNode *redfs(vector<string> tokens) { string temp = tokens[idx++]; };
void bfs(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    q.push(root);
    string ans;
    while (!q.empty()) {
        // int size = q.size();
        // for (int i = 0; i < size; i++){
        // string temp;
        auto t = q.front();
        q.pop();

        ans += to_string(t->val) + ",";
        if (t->left != nullptr) {
            ans += to_string(t->left->val);
            q.push(t->left);
        } else {
            ans += "#,";
        }
        if (t->right != nullptr) {
            ans += to_string(t->right->val) + ",";
            q.push(t->right);
        } else {
            ans += "#,";
        }
        // }
    }
    // return ans;
}
TreeNode *rebfs(vector<string> &tokens) {}
int main() {
    cin >> str;
    istringstream iss(str);
    while (getline(iss, token, ',')) {
        tokens.push_back(token);
    }

    TreeNode *root = rebfs(tokens);
    bfs(root);
    ans.pop_back();
    cout << ans << endl;

    return 0;
}