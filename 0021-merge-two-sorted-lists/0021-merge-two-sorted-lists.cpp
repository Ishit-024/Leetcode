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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       map<int,int>mp;
       if(list1==NULL && list2==NULL){
        return NULL;
       }
       else if(list1==NULL && list2!=NULL){
        return list2;
       }
       else if(list2==NULL && list1!=NULL){
        return list1;
       }
       ListNode* temp1 = list1;
       ListNode* temp2 = list2;
        ListNode* x;
        while(temp1!=NULL){
            mp[temp1->val]++;
            x=temp1;
            temp1=temp1->next;
        }
        temp1=list1;
        while(temp2!=NULL){
            mp[temp2->val]++;
            temp2=temp2->next;
        }
        x->next=list2;
        for(auto &i:mp){
            for(int j=0;j<i.second;j++){
                temp1->val=i.first;
                temp1=temp1->next;
            }
            }
            return list1;
        }
};
