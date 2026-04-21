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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; // Moves one step at a time
        ListNode* fast = head; // Moves two steps at a time

        // Continue until 'fast' reaches the end of the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move slow pointer by 1
            fast = fast->next->next; // Move fast pointer by 2
        }

        // When 'fast' reaches the end, 'slow' is exactly in the middle
        return slow;
    }
};