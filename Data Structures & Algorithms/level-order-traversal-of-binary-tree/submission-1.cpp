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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> nodes;
        TreeNode* levelEnd = root;
        nodes.push(root);
        
        while (!nodes.empty()) {
            vector<int> level;
            int size = nodes.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* curr = nodes.front();
                nodes.pop();

                if (curr) {
                    level.push_back(curr->val);
                    nodes.push(curr->left);
                    nodes.push(curr->right);
                }
            }
            
            if (!level.empty()) res.push_back(level);
        }

        return res;
    }
};
