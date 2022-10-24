/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        if (root == nullptr) return data;
        
        std::queue<TreeNode *> q;
        q.push(root);
        TreeNode* node = nullptr;
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            if (node == nullptr) {
                data += "null ";
            }
            else {
                data += std::to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        // std::cout << data << std::endl;
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        
        stringstream ss(data);
        string str;
        getline(ss, str, ' ');
        
        std::queue<TreeNode *> q;
        
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        TreeNode *node;
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            getline(ss, str, ' ');
            
            
            if (str == "null") {
                node->left = nullptr;
            }
            else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            getline(ss, str, ' ');
            
            
            if (str == "null") {
                node->right = nullptr;
            }
            else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));