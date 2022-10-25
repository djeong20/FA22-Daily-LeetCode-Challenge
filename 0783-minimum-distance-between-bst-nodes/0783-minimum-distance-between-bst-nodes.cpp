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
    int minDiffInBST(TreeNode* root) {
        std::queue<TreeNode *> q;
        q.push(root);
        
        TreeNode *node = nullptr;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        
        int minDiff = INT_MAX;
        int diff;
        
        while (!q.empty()) {
            node = q.front();
            left = node->left;
            right = node->right;
            q.pop();
            
            if (left) {
                q.push(left);
                
                while (left->right != nullptr) {
                    left = left->right;
                }
                diff = node->val - left->val;
                
                minDiff = diff < minDiff ? diff : minDiff;
            }
            if (right) {
                q.push(right);
                
                while (right->left != nullptr) {
                    right = right->left;
                }
                diff = right->val - node->val;
                
                minDiff = diff < minDiff ? diff : minDiff;
            }
        }
        
        return minDiff;
    }
};