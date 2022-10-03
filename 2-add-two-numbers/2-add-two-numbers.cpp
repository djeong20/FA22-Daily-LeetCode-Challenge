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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *curr = result;

        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        bool carry = false;
        int count = 0;
        
        while (ptr1 != nullptr || ptr2 != nullptr || carry) {
            int sum = carry ? 1 : 0;
            
            if (ptr1 != nullptr) {
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }
            if (ptr2 != nullptr) {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            
            carry = (sum > 9) ? true : false;
            curr->val = sum % 10;
        
            if (ptr1 != nullptr || ptr2 != nullptr || carry) {
                curr->next = new ListNode();
                curr = curr->next;
            }
        }
        
        return result;
    }
};