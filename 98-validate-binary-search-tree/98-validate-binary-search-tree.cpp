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
    bool inorderTraversal(TreeNode* node, vector<int> &nums) {
        if (node == nullptr) {
            return true;
        }
        
        bool l = inorderTraversal(node->left, nums);
        
        int n = nums.size();
        if (n > 0 && nums[n-1] >= node->val) {
            return false;
        }
        
        nums.push_back(node->val);
        
        bool r = inorderTraversal(node->right, nums);
        
        return l && r;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        return inorderTraversal(root, nums);
    }
};