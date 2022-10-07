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
    vector<vector<int>> res;
    
    void recursiveLevelOrder(TreeNode* node, int level) {
        if (node == nullptr) {
            return;
        }
        
        if (res.size() == level) {
            res.push_back(vector<int>());
        }
        res[level].push_back(node->val);
        
        recursiveLevelOrder(node->left, level+1);
        recursiveLevelOrder(node->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        recursiveLevelOrder(root, 0);
        
        return res;
    }
};