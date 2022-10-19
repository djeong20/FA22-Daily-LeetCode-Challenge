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
    vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode *> q;
        std::vector<double> res;
        TreeNode *curr = nullptr;
        if (root) q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            double val = 0;
            for (int i = 0; i < n; i++) {
                curr = q.front();
                val += curr->val;
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
                q.pop();
            }
            
            res.push_back(val/n);
        }
        
        return res;
    }
};