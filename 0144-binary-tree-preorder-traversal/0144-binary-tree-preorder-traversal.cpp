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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (root == nullptr) return res;
        
        std::stack<TreeNode *> st;
        st.push(root);
        TreeNode *curr = nullptr;
        
        while (!st.empty()) {
            curr = st.top();
            res.push_back(curr->val);
            st.pop();
            
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
        }
        
        return res;
    }
};