/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> s;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        
        while (curr) { 
            if (s.find(curr->val) == s.end()) {
                s.insert(curr->val);
                prev = curr;
            }
            else {
                prev->next = curr->next;
            }
            
            curr = curr->next;        
        }
        
        return head;
        
    }
};