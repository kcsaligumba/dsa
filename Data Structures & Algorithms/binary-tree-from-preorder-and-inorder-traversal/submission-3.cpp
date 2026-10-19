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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode dummy(0);
        TreeNode* curr = &dummy;
        int preIdx = 0;
        int inIdx = 0;
        int n = preorder.size();

        while (preIdx < n && inIdx < n) {
            curr->right = new TreeNode(preorder[preIdx], nullptr, curr->right);
            curr = curr->right;
            preIdx++;

            while (preIdx < n && curr->val != inorder[inIdx]) {
                curr->left = new TreeNode(preorder[preIdx], nullptr, curr);
                curr = curr->left;
                preIdx++;
            }

            inIdx++;

            while (curr->right && curr->right->val == inorder[inIdx]) {
                TreeNode* prev = curr->right;
                curr->right = nullptr;
                curr = prev;
                inIdx++;
            }
        }

        return dummy.right;
    }
};
