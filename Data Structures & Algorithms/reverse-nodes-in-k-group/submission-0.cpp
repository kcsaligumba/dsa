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
        bool first = true;
        ListNode* start = head;
        ListNode* connection = nullptr;
        while (true) {
            ListNode* prev = start;
            int count = 0;
            while (prev && count < k) {
                prev = prev->next;
                count++;
            }
            if (count == k) {
                ListNode* nextStart = prev;
                ListNode* curr = start;
                ListNode* temp;
                while (curr && curr != nextStart) {
                    temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                }
                if (first) {
                    head = prev;
                    first = false;
                }
                if (connection) {
                    connection->next = prev;
                }
                connection = start;
                start = nextStart;
            }
            else break;
        }
        
        return head;
    }
};
