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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* itr = head;
        ListNode* tail = head;
        int len = 0;
        
        while (itr != nullptr) {
            len++;
            tail = itr;
            itr = itr->next;
        }
        
        k %= len;
        
        if (k == 0) {
            return head;
        }
        
        itr = head;
        ListNode* prev = nullptr;
    
        for (int i = 0; i < len-k; i++) {
            prev = itr;
            itr = itr->next;
        }
        
        ListNode* newHead = itr;
        tail->next = head;
        prev->next = nullptr;
        
        return newHead;
    }
};