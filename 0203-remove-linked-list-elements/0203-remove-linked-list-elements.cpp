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
   
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL && head->val!=val){
            return head;
        }
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
            if(curr->val==val){
                ListNode*x=curr->next;
                if(prev!=NULL){
                prev->next=x;
                delete curr;
                curr=x;
                }
                else{
                delete curr;
                curr=x; 
                head=curr;
                }
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};