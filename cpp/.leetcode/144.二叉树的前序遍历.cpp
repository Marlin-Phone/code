/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void bianli(TreeNode *root, vector<int> &vec) {
        if (root == nullptr) {
            return;
        }
        vec.push_back(root->val);
        bianli(root->left, vec);
        bianli(root->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        bianli(root, vec);
        return vec;
    }
};
// @lc code=end
