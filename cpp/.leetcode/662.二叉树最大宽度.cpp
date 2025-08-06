#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode *root) {
        unsigned int ans = 0;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode *> que;
        queue<unsigned int> nums;
        que.push(root);
        nums.push(1);
        while (!que.empty()) {
            int size = que.size();
            unsigned int l, r;
            for (int i = 0; i < size; i++) {
                auto t = que.front();
                unsigned int num = nums.front();
                que.pop();
                nums.pop();
                if (i == 0) {
                    l = num;
                }
                if (i == size - 1) {
                    r = num;
                }
                if (t->left) {
                    que.push(t->left);
                    nums.push(num * 2);
                }
                if (t->right) {
                    que.push(t->right);
                    nums.push(num * 2 + 1);
                }
            }
            ans = max(ans, (r - l) + 1);
        }
        return ans;
    }
};
// @lc code=end
