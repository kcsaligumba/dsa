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
        ListNode* curr = head;
        ListNode* nextNode = head->next;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        while (nextNode && nextNode != tail && tail->next != nextNode) {
            curr->next = tail;
            curr = curr->next;
            curr->next = nextNode;
            
            tail = nextNode;
            while (tail->next != curr) {
                tail = tail->next;
            }

            nextNode = nextNode->next;
            curr = curr->next;
        }
        tail->next = nullptr;
    }
};
