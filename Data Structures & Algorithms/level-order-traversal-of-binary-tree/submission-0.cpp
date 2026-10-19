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
            while (true) {
                if (nodes.front()) {
                    level.push_back(nodes.front()->val);
                    if (nodes.front()->left) nodes.push(nodes.front()->left);
                    if (nodes.front()->right) nodes.push(nodes.front()->right);
                }
                if (nodes.front() == levelEnd) {
                    nodes.pop();
                    levelEnd = nodes.back();
                    break;
                }
                else {
                    nodes.pop();
                }   
            }
            res.push_back(level);
        }

        return res;
    }
};
