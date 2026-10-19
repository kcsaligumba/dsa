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
private: 
    vector<int> res;
public:
    int maxPathSum(TreeNode* root) {
        res.push_back(root->val);
        maxWithoutSplit(root);
        return res[0];
    }

    int maxWithoutSplit(TreeNode* root) {
        if (!root) return 0;

        int leftMax = max(0, maxWithoutSplit(root->left));
        int rightMax = max(0, maxWithoutSplit(root->right));
        res[0] = max(res[0], root->val + leftMax + rightMax);

        return root->val + max(leftMax, rightMax);
    }
};
