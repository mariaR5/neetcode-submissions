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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* prevTail = NULL;
        int count = 1;
        bool first = true;

        while (right) {
            if (count == k) {
                ListNode* temp1 = right->next;

                // Reverse from left to right
                ListNode* cur = left;
                ListNode* prev = NULL;
                while (cur != temp1) {
                    ListNode* temp2 = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp2;
                }
                
                left->next = temp1;
                if (first) {
                    first = false;
                    head = prev;
                }
                else {
                    prevTail->next = prev;
                }
                prevTail = left;
                left = temp1;
                right = temp1;
                count = 1;
            }
            else {
                right = right->next;
                count++;
            }
        }

        return head;
    }
};
