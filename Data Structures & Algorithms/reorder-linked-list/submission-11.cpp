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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cur = head;

        while (cur) {
            st.push(cur);
            cur = cur->next;
        }

        ListNode* left = head;
        int n = st.size();

        for (int i = 0; i < n/2; i++) {
            ListNode* right = st.top();
            st.pop();

            ListNode* temp = left->next;
            left->next = right;
            right->next = temp;
            left = temp;
        }

        left->next = NULL;
    }
};
