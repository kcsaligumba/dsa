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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            ListNode *l1, *l2;

            for (int i = 0; i < lists.size(); i += 2) {
                l1 = lists[i];
                l2 = ((i + 1) < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(merge(l1, l2));
            }

            lists = mergedLists;
        }

        return lists[0];
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode* curr = &head;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1) {
            curr->next = list1;
        }
        else if (list2) {
            curr->next = list2;
        }
        
        return head.next;
    }
};
