/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false; // An empty list or a list with only one node cannot have a cycle
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // Move slow pointer by 1 step
            fast = fast->next->next;     // Move fast pointer by 2 steps
            
            if (slow == fast) {
                return true; // Cycle detected
            }
        }
        
        return false; // No cycle detected
    }
};
