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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root == nullptr) {
            return res;
        }
        
        queue<TreeNode *> q;
        TreeNode *node = nullptr;
        q.push(root);
        
        bool reverse = false;
        
        while (!q.empty()) {
            int s = q.size();
            vector<int> v;
            
            for (int i = 0; i < s; i++) {
                node = q.front();
                q.pop();
                
                if (reverse) {
                    v.insert(v.begin(), node->val);
                } else{
                    v.push_back(node->val);    
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);                
            }
            
            reverse = !reverse;
            res.push_back(v);
        }
        
        return res;
        
    }
};