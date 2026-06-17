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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, bool> lnAddys;
        while (head) {
            if (lnAddys.contains(head)) {
            // if (lnAddys[head]) {
                return true; 
            }
            else {
                lnAddys[head] = true;
            }
            head = head->next; 
        }
        return false; 
    }
};
