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
    // Merge two sorted Linked Lists
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        
        ListNode *head = l1->val <= l2->val ? l1 : l2;
        ListNode *curr = head;
        
        if (head == l1) {
            l1 = l1->next;
        } else{
            l2 = l2->next;
        }
        
        while (true) {
            if (l1 == nullptr) {
                curr->next = l2;
                break;
            }
            if (l2 == nullptr) {
                curr->next = l1;
                break;
            }
            
            if (l1->val <= l2->val) {
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            } else {
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
        }
        
        return head;
    }
    
    // Recursive solution (Merge Sort)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();
        
        // Base cases
        if (N == 0) {
            return nullptr;
        }
        if (N == 1) {
            return lists[0];
        }
        if (N == 2){
            return mergeLists(lists[0], lists[1]);
        }
        
        vector<ListNode*> left;
        vector<ListNode*> right;
        
        for (int i = 0; i < N; i++) {
            if (i < N/2) {
                left.push_back(lists[i]);
            }
            else {
                right.push_back(lists[i]);
            }
        }
        
        return mergeLists(mergeKLists(left), mergeKLists(right));
    }
};