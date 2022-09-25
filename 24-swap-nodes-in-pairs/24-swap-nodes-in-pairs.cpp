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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        head = p2;
        
        while (p1->next != nullptr) {
            p1->next = p2->next;
            p2->next = p1;
            ListNode *p1_new = p1->next;
            
            if (p1_new && p1_new->next) {
                p1->next = p1_new->next;
            } 
            
            p1 = p1_new;
            
            if (p1)
                p2 = p1->next;
            else
                break;
        }
        
        return head;
    }
};