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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Catch edge cases
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        // Set the head to be the smaller head of the two lists.
        // This is eventually what we're returning
        ListNode* l1p = list1;
        ListNode* l2p = list2;
        ListNode* head;
        ListNode* curr;

        if (l1p->val < l2p->val) {
            head = l1p;
            curr = l1p;
            l1p = l1p->next;
        }
        else {
            head = l2p;
            curr = l2p;
            l2p = l2p->next;
        }

        // While both lists are not empty
        while (l1p && l2p) {
            if (l1p->val < l2p->val) { 
                curr->next = l1p;
                l1p = l1p->next;
            }
            else {
                curr->next = l2p;
                l2p = l2p->next;
            }
            curr = curr->next;
        }

        // Append the remainder of whichever list still has elements
        // onto the current list
        // If l1p still has elements, append it to curr
        if (l1p) {
            curr->next = l1p;
        }
        else if (l2p) {
            curr->next = l2p;
        }
        return head; 
    }
};
