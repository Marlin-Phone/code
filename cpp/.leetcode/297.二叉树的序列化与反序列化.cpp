/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:
    string ans;
    int idx = 0;

    void f(TreeNode *root) {
        if (root == nullptr) {
            ans += "null,";
            return;
        }
        ans += to_string(root->val) + ",";
        f(root->left);
        f(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        f(root);
        ans.pop_back();
        return ans;
    }

    TreeNode *p(vector<string> &tokens) {
        string temp = tokens[idx++];
        if (temp == "null") {
            return nullptr;
        }
        TreeNode *head = new TreeNode(stoi(temp));
        head->left = p(tokens);
        head->right = p(tokens);
        return head;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        TreeNode *head;
        vector<string> tokens;
        string token;
        istringstream iss(data);
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        head = p(tokens);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));