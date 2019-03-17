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
    ListNode* mergeTwoList(ListNode* p, ListNode* q) {
        ListNode* tmp = new ListNode(0);
        ListNode* head = tmp;
        while(p != NULL && q != NULL) {
            if (p->val < q->val) {
                // tmp->next = new ListNode(p->val);
                tmp->next = p;
                tmp = tmp->next;
                p = p->next;
            }
            else {
                // tmp->next = new ListNode(q->val);
                tmp->next = q;
                tmp = tmp->next;
                q = q->next;
            }
        }
        while (p != NULL) {
            // tmp->next = new ListNode(p->val);
            tmp->next = p;
            tmp = tmp->next;
            p = p->next;
        }
        while (q != NULL) {
            // tmp->next = new ListNode(q->val);
            tmp->next = q;
            tmp = tmp->next;
            q = q->next;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0);
        if (lists.size() >= 2) {
            ans = mergeTwoList(lists[0], lists[1]);
            for (int i = 2; i < lists.size(); ++i)
                ans = mergeTwoList(ans, lists[i]);
        }
        else if (lists.size() == 1)
            ans = lists[0];
        else
            ans = NULL;
        return ans;
    }
};