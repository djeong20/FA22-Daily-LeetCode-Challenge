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
    bool recursivePathSum(TreeNode* node, int targetSum, int currSum) {
        
        if (node == nullptr) {
            return false;
        }
        
        currSum += node->val;
        
        if (node->left == nullptr && node->right == nullptr && currSum == targetSum) {
            return true;
        }
        else {
            return recursivePathSum(node->left, targetSum, currSum) || recursivePathSum(node->right, targetSum, currSum);
        }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recursivePathSum(root, targetSum, 0);
    }
};