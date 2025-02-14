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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(root==NULL){
            return v;
        }
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            TreeNode*x=it.first;
            int y=it.second;
            q.pop();
            mp[y]=x->val;
            if(x->left!=NULL){
                q.push({x->left,y+1});
            }
            if(x->right!=NULL){
                q.push({x->right,y+1});
            }
        }
        for(auto i:mp){
            v.push_back(i.second);
        }
        return v;
    }
};