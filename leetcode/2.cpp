struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* res = result;
        int bit = 0; int tmp;
        for(; l1 != NULL && l2 != NULL; l1 = l1 -> next, l2 = l2 -> next) {
            tmp = l1 -> val + l2 -> val + bit;
            res -> next = new ListNode(tmp % 10);
            res = res -> next;
            bit = tmp / 10;
        }       
        if(l1 != NULL) {
            for(; l1 != NULL; l1 = l1 -> next) {
                tmp = l1 -> val + bit;
                res -> next = new ListNode(tmp % 10);
                res = res -> next;
                bit = tmp / 10;
            }
        } else if(l2 != NULL) {
            for(; l2 != NULL; l2 = l2 -> next) {
                tmp = l2 -> val + bit;
                res -> next = new ListNode(tmp % 10);
                res = res -> next;
                bit = tmp / 10;;
            }
        } 
        if(bit != 0) {
            res -> next = new ListNode(bit);
        }
        return result -> next;
    }
};