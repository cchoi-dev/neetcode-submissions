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
    ListNode* reverseList(ListNode* head) {
        // The first way I can think of to reverse a linked list is to
        // have 
        
        // Getting some edge cases out of the way first..
        if (!head) {
            // LL size = 0
            return head;
        }
        if (!head->next) {
            // LL size = 1
            return head;
        }

        ListNode* backPtr = head;
        ListNode* currPtr = head->next;
        backPtr->next = nullptr;

        while (currPtr != nullptr) {
            printf("currPtr %d", currPtr->val);
            ListNode* nextPtr = currPtr->next;
            // Make curr node point to prev node
            currPtr->next = backPtr;
            // Iterate forward
            backPtr = currPtr;
            currPtr = nextPtr;
        }
        return backPtr;
    }
};
