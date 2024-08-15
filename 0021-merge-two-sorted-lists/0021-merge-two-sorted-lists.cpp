class Solution {
public:
    ListNode* compare(ListNode* &list1,ListNode* &list2){
        if(list1->next==NULL){ // No need to change this line
            list1->next=list2; 
            return list1;
        }
        
        ListNode* curr1 = list1; // Corrected variable names for better readability
        ListNode* curr2 = list2;
        ListNode* next1 = curr1->next;
        ListNode* next2 = curr2->next;
        
        while(next1 != NULL && curr2 != NULL){
            if(curr2->val >= curr1->val && curr2->val <= next1->val){
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
            } else {
                curr1 = next1;
                next1 = next1->next;
                if(next1 == NULL){
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) {
            return list2; // simplified the condition
        }
        if(list2 == NULL) {
            return list1; // simplified the condition
        }

        // The check was incorrect, added null check for list1->next and corrected the condition
        if(list2->val <= list1->val) { // This condition was incorrect
            return compare(list2, list1); 
        } else {
            return compare(list1, list2);
        }
    }
};
