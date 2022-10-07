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
        vector<vector<int>> res;
        std::queue<std::pair<TreeNode *, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (node == nullptr) {
                continue;
            }
            
            if (res.size() == level) {
                res.push_back(vector<int>());
            }
            
            res[level].push_back(node->val);
            
            if (node != nullptr) {
                q.push({node->left, level+1});
                q.push({node->right, level+1});
            }
        }
        
        return res;
        
    }
};