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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode*curr=head;
       if(curr==NULL){
        return NULL;
       }
       else if(curr->next==NULL){
        return curr;
       }
       while(curr!=NULL){
            if(curr->next!=NULL && curr->val==curr->next->val){
                    ListNode*x=curr->next->next;
                    ListNode*del=curr->next;
                    curr->next=x;
                    delete(del);
                }
            else{
                curr=curr->next;
            }
       }
       return head;
    }
};