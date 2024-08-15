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
    ListNode* sortList(ListNode* head) {
        map<int,int>mp;
        ListNode*temp=head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        for(auto &i:mp){
            for(int j=0;j<i.second;j++){
                temp->val=i.first;
                temp=temp->next;
            }
        }
        return head;
    }
};