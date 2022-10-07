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
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode *> q1;
        std::queue<TreeNode *> q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode *l = q1.front();
            TreeNode *r = q2.front();
            // pop curr
            q1.pop();
            q2.pop();
            
            if (l == nullptr && r == nullptr) {
                continue;
            }
            else if ((l != nullptr && r == nullptr) || (l == nullptr && r != nullptr)) {
                return false;
            }
            
            if (l->val != r->val) {
                cout << "Value is different" << endl;
                cout << l->val << " " << r->val << endl;
                return false;
            }
            
            // left
            q1.push(l->left);
            q1.push(l->right);
            // right
            q2.push(r->right);
            q2.push(r->left);
        }
        
        if (q1.empty() && q2.empty()) {
            return true;
        }
        return false;
        
    }
};