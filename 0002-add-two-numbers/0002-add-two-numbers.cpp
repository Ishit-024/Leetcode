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
    void insertAtTail(ListNode* &head,ListNode*&tail,ListNode* &node1){
        int data=node1->val;
        if(head==NULL){
            head=node1;
            tail=node1;
        }
        else{
            tail->next=node1;
            tail=node1;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* head1=l1;
       ListNode* head2=l2;
       ListNode* head=NULL;
       ListNode* tail=NULL;
       int carry=0;
       while(head1!=NULL && head2!=NULL){
        int val1=head1->val;
        int val2=head2->val;
        int sum=val1+val2+carry;
        int digit=sum%10;
        ListNode* node1=new ListNode(digit);
        insertAtTail(head,tail,node1);
        carry=sum/10;
        head1=head1->next;
        head2=head2->next;
       }
       while(head2!=NULL){
        int val2=head2->val;
        int sum=carry+val2;     
        int digit=sum%10;
        ListNode* node2=new ListNode(digit);
        insertAtTail(head,tail,node2);
        carry=sum/10;
        head2=head2->next;
         }
        while(head1!=NULL){
        int val1=head1->val;
        int sum=carry+val1;     
        int digit=sum%10;
        ListNode* node1=new ListNode(digit);
        insertAtTail(head,tail,node1);
        carry=sum/10;
        head1=head1->next;
         }
         if(carry==1){
         ListNode *node1=new ListNode(carry);
        insertAtTail(head,tail,node1);
         }
        return head;
    }
};