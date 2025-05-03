/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    void dfs(TreeNode *root, vector<int> &vec) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, vec);
        dfs(root->right, vec);
        vec.push_back(root->val);
    };
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        dfs(root, vec);
        return vec;
    }
};
// @lc code=end
