/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
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
    void f(TreeNode *root, string &builder) {
        if (root == nullptr) {
            builder += "#,";
        } else {
            builder += to_string(root->val);
            builder += ',';
            f(root->left, builder);
            f(root->right, builder);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string builder;
        f(root, builder);
        if (!builder.empty()) {
            builder.pop_back();
        }
        return builder;
    }

    TreeNode *g(vector<string> &nodes, int &index) {
        if (index >= nodes.size() || nodes[index] == "#") {
            index++;
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(nodes[index]));
        index++;

        node->left = g(nodes, index);
        node->right = g(nodes, index);

        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }
        int index = 0;
        return g(nodes, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
