/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode *> que;
        que.push(root);
        int flag = 0;
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                auto t = que.front();
                temp.push_back(t->val);
                que.pop();
                if (t->left) {
                    que.push(t->left);
                }
                if (t->right) {
                    que.push(t->right);
                }
            }
            if (flag == 1) {
                reverse(temp.begin(), temp.end());
                flag = 0;
            } else {
                flag = 1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end
