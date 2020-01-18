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
    vector<int> nextLargerNodes(ListNode* head) {
        int cnt = 0;
        vector<int> ans;
        stack<pair<int, int>> st;
        while (head) {
            ans.push_back(0);
            while (!st.empty() && head->val > st.top().first) {
                ans[st.top().second] = head->val;
                st.pop();
            }
            st.push(make_pair(head->val, cnt++));
            head = head->next;
        }
        return ans;
    }
};