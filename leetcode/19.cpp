/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cut, *last;
        cut = head; last = head;
        for (int i = 0; i < n; ++i) last = last->next;
        
        if (last == NULL) return head->next;
        while (last->next != NULL) {
            cut = cut->next;
            last = last->next;
        }
        cut->next = cut->next->next;
        return head;
    }
};