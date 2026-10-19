/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        isGood(root, root->val, res);
        return res;
    }

    void isGood(TreeNode* root, int maxVal, int& res) {
        if (!root) return;
        if (root->val >= maxVal) {
            res++;
            maxVal = root->val;
        }
        isGood(root->left, maxVal, res);
        isGood(root->right, maxVal, res);
    }
};
