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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        std::queue<TreeNode *> q;
        q.push(root);
        
        TreeNode *node = nullptr;
        
        while (!q.empty()) {
            int maxVal = INT_MIN;
            int n = q.size();
            
            for (int i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                
                maxVal = maxVal < node->val ? node->val : maxVal;
                
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            } 
            
            res.push_back(maxVal);
        }
        
        return res;
    }
};