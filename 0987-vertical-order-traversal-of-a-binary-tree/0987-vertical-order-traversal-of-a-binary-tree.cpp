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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // key: col, value: value in row
        vector<vector<int>> res;
        std::unordered_map<int, std::vector<int>> all;
        
        
        // TreeNode, col
        std::queue<std::pair<TreeNode *, int>> q;
        q.push({root, 0});
        
        TreeNode *node = nullptr;
        int n, col;
        int minCol = 0;
        int maxCol = 0;
        
        // 1. traverse tree (level-order)
        while (!q.empty()) {
            n = q.size();
            std::unordered_map<int, std::vector<int>> level;
            
            for (int i = 0; i < n; ++i) {
                auto v = q.front(); q.pop();
                node = v.first;
                col = v.second;
                
                minCol = col < minCol ? col : minCol;
                maxCol = col > maxCol ? col : maxCol;
                
                if (level.find(col) == level.end()) {
                    level[col] = {node->val};
                }
                else {
                    level[col].push_back(node->val);    
                }
                
                if (node->left) q.push({node->left, col-1});
                if (node->right) q.push({node->right, col+1});
            }
            
            for (auto i : level) {
                int key = i.first;
                
                if (all.find(key) == all.end()) {
                    std::sort(level[key].begin(), level[key].end());
                    all[key] = level[key];
                }
                else {
                    std::sort(level[key].begin(), level[key].end());
                    all[key].insert(all[key].end(), level[key].begin(), level[key].end());    
                }
            }
        }
        
        for (int i = minCol; i <= maxCol; ++i) {
            res.push_back(all[i]);
        }
        
        return res;
    }
};