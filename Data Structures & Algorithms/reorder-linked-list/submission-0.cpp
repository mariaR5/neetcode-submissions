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

        ListNode* right = st.top();
        ListNode* left = head;

        while (left < right) {
            ListNode* temp = left->next;
            left->next = right;
            right->next = temp;
            left = temp;
            st.pop();
            right = st.top();
        }
        left->next = NULL;
    }
};
