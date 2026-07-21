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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int rem = 0;

        while(l1 && l2) {
            int sum = l1->val + l2->val + rem;
            ListNode* newNode = new ListNode(sum%10);
            cur->next = newNode;
            rem = sum/10;

            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }

        while(l1) {
            int sum = l1->val + rem;
            ListNode* newNode = new ListNode(sum%10);
            cur->next = newNode;
            rem = sum/10;

            l1 = l1->next;
            cur = cur->next;
        }

        while(l2) {
            int sum = l2->val + rem;
            ListNode* newNode = new ListNode(sum%10);
            cur->next = newNode;
            rem = sum/10;

            l2 = l2->next;
            cur = cur->next;
        }

        if (rem > 0) {
            ListNode* newNode = new ListNode(rem);
            cur->next = newNode;
        }

        return dummy->next;
    }
};
