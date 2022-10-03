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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> p_queue;
        std::queue<TreeNode*> q_queue;
        
        if (p != nullptr) {
            p_queue.push(p);
            
        } 
        
        if (q != nullptr) {
            q_queue.push(q);
        }
        
        
        while (!p_queue.empty() && !q_queue.empty()) {
            TreeNode *curr_p = p_queue.front();
            TreeNode *curr_q = q_queue.front();
            
            if (curr_p->val != curr_q->val) {
                return false;
            }
            
            if (curr_p->left != nullptr && curr_q->left != nullptr) {
                p_queue.push(curr_p->left);
                q_queue.push(curr_q->left);
            } 
            else if (curr_p->left != curr_q->left) {
                return false;
            }
            if (curr_p->right != nullptr && curr_q->right != nullptr) {
                p_queue.push(curr_p->right);
                q_queue.push(curr_q->right);
            }
            else if (curr_p->right != curr_q->right) {
                return false;
            }
            
            p_queue.pop();
            q_queue.pop();
        }
        
        if (p_queue.empty() && q_queue.empty()) {
            return true;
        }
        
        return false;
    }
};