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
    ListNode* middleNode(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*current=head;
        if(head->next==NULL){
            return head;
        }
        else if(head==NULL){
            return prev;
        }
        // while(current!=NULL){
        //     if(current->next==NULL){
        //         return prev;
        //     }
        //     prev=current;
        //     current=current->next->next;
        //     }
        //     return prev;
        // }
        int count=0;
        while(current!=NULL){
            count++;
            current=current->next;
        }
        ListNode*temp=head;
        int x=count/2;
        int count1=0;
        while(count1!=x){
            temp=temp->next;
            count1++;
        }
        return temp;
    }
};