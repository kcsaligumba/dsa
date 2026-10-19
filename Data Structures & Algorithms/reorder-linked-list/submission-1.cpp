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
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = nullptr;
        ListNode* temp = slow->next;
        slow->next = nullptr;
        slow = temp;
        while (slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        ListNode* curr = head;
        ListNode* left = head->next;
        ListNode* right = prev;
        while (left && right) {
            curr->next = right;
            right = right->next;
            curr = curr->next;

            curr->next = left;
            left = left->next;
            curr = curr->next;
        }
        if (right) {
            curr->next = right;
        }
    }
};
