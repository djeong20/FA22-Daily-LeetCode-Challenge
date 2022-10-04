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
    bool recursivePathSum(TreeNode* node, int targetSum, int currentSum) {
        bool isLeaf = node->left == nullptr && node->right == nullptr;
        
        if (isLeaf && node->val + currentSum == targetSum) {
            return true;
        }
        
        if (node->left != nullptr && node->right != nullptr) {
            return recursivePathSum(node->left, targetSum, currentSum + node->val) || recursivePathSum(node->right, targetSum, currentSum + node->val);
        }
        else if (node->left != nullptr && node->right == nullptr) {
            return recursivePathSum(node->left, targetSum, currentSum + node->val);
        }
        else if (node->left == nullptr && node->right != nullptr) {
            return recursivePathSum(node->right, targetSum, currentSum + node->val);
        }
        
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return recursivePathSum(root, targetSum, 0);
    }
};