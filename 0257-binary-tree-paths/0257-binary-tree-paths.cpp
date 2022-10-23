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
    // string
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        
        if (root == nullptr) return res;        
        dfsRecursive(root, "", res);
        
        return res;
    }
    
    void dfsRecursive(TreeNode* node, string path, vector<string> &res) {
        
        path += "->" + std::to_string(node->val);
        
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(path.substr(2));
            return;
        }
        
        if (node->left != nullptr) {
            dfsRecursive(node->left, path, res);
        }
        if (node->right != nullptr) {
            dfsRecursive(node->right, path, res);
        }
    }
};