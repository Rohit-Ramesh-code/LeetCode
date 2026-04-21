/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node. We use a local variable instead of 'new' to avoid a memory leak.
        ListNode dummy(0); 
        ListNode* tail = &dummy; // 'tail' will point to the last node of our growing merged list

        // Compare the heads of both lists until one is exhausted
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;   // Attach the smaller node
                list1 = list1->next;  // Move list1 forward
            } else {
                tail->next = list2;   // Attach the smaller node
                list2 = list2->next;  // Move list2 forward
            }
            tail = tail->next;        // Move our tail pointer forward
        }

        // At this point, at least one list is empty. 
        // We just attach the remainder of the other list directly to the end.
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // The actual merged list starts at the node immediately following our dummy.
        return dummy.next;
    }
};