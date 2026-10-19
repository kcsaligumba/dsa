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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        int node = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            count++;
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            if (node == count - n) {
                if (prev == nullptr) {
                    head = head->next;
                    delete curr;
                }
                else {
                    prev->next = prev->next->next;
                    delete curr;
                }
                return head;
            }
            node++;
            prev = curr;
            curr = curr->next;
        }
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};
