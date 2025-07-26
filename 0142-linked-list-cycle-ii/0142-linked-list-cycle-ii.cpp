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
ListNode* findLoop(ListNode* &head){
 ListNode*slow=head;
 ListNode*fast=head;
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow){
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
       if(head==NULL || head->next==NULL){
        return NULL;
       }
       else if(head->next==head){
        return head;
       }
       else if(findLoop(head)==NULL){
        return NULL;
       }
       ListNode* x=findLoop(head); //gets slow pointer or fast pointer
       ListNode* y=head;
       while(x!=y){
        x=x->next;
        y=y->next;
       }
       return y;
    }
};