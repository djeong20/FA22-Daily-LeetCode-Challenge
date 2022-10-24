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
    int findBottomLeftValue(TreeNode* root) {
        
        // use iterative bfs 
        std::queue<TreeNode *> q;
        q.push(root);
        
        int res = root->val;
        int n;
        
        TreeNode *node = nullptr;
        
        while (!q.empty()) {
            n = q.size();
            
            for (int i = 0; i < n; i++) {
                node = q.front();
                q.pop();
                
                res = node->val;
                
                if (node->right != nullptr) q.push(node->right);
                if (node->left != nullptr) q.push(node->left);
            }
        }
        
        return res;
    }
};