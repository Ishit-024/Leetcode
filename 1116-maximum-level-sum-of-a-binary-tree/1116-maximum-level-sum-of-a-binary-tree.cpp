/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        map<int,int> mp;
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int sum=0;
        int x;
        while(!q.empty()){
            auto it=q.front();
            TreeNode* node=it.first; //node
            int x=it.second;  //level
            q.pop();
            if(!mp[x]){
                mp[x]=node->val;
            }
            else{
                mp[x]=mp[x]+node->val;
            }
            if(node->left!=NULL){
                q.push({node->left,x+1});
            }
            if(node->right!=NULL){
                q.push({node->right,x+1});
            }
        }
        int maxi=INT_MIN;
        int z=1;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        for(auto j:mp){
            if(maxi==j.second){
                 z=j.first;
                 break;
            }
        }
        return z;
    }
};