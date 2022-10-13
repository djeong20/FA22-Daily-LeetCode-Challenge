/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node *> q;
        Node *curr = nullptr;
        
        if (root != nullptr) {
            q.push(root);
        }
        
        while (!q.empty()) {
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                curr = q.front();
                q.pop();
                
                if (!q.empty()) 
                    curr->next = q.front();
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            curr->next = nullptr;
        }
        
        return root;
    }
};