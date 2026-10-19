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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        TreeNode* iop = root->left;
        while (iop && iop->right) {
            iop = iop->right;
        }
        if (iop && iop->val >= root->val) return false;

        TreeNode* ios = root->right;
        while (ios && ios->left) {
            ios = ios->left;
        }
        if (ios && ios->val <= root->val) return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }
};
