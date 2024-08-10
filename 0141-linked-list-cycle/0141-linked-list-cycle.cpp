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
        ListNode*temp=head;
        if (head == NULL || head->next == NULL) {
            return false; // An empty list or a list with only one node cannot have a cycle
        }
        unordered_map<ListNode*,bool>mp(0);
        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                return true;
            }
            mp[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};