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
        ListNode head;
        ListNode* curr = &head;
        int sum = 0;
        while (l1 && l2) {
            sum += l1->val + l2->val;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            sum /= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            sum += l1->val;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            sum /= 10;
            l1 = l1->next;
        }
        while (l2) {
            sum += l2->val;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            sum /= 10;
            l2 = l2->next;
        }
        if (sum != 0) {
            curr->next = new ListNode(sum);
        }

        return head.next;
    }
};
