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
    // 1. check curr
    // 2. check left (if not nullptr), insert to right
    //    insert to right:  1. curr->left->right->right->...->right = curr->right, 
    //                      2. curr->right = curr->left
    // 3. go to right
    // continue until right is nullptr
    
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        TreeNode *c = nullptr;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                c = curr->left;
                
                while (c->right != nullptr) {
                    c = c->right;
                }
                
                c->right = curr->right;
                curr->right = curr->left;
            }
            curr->left = nullptr;
            curr = curr->right;
        }
    }
};