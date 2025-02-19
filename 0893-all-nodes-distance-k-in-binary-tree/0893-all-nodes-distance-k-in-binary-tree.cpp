/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool leaf(TreeNode* root){
        if(root->right==NULL && root->left==NULL){
            return true;
        }
        return false;
    }
public:
    void makeparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
        if(root==NULL){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top->left!=NULL){
                mp[top->left]=top;
                q.push(top->left);
            }
            if(top->right!=NULL){
                mp[top->right]=top;
                q.push(top->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*>mp;
       makeparent(root,mp);
     vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target]=true;
        int count=0;
        while(!q.empty()){
            if(count==k){
                break;
            }
            int size=q.size();
            for(int i=0;i<size;i++){
            TreeNode* top=q.front();
            q.pop();
            if(top->left && !visited[top->left]){
                q.push(top->left);
                visited[top->left]=true;
            }
            if(top->right && !visited[top->right]){
                q.push(top->right);
                visited[top->right]=true;
            }
            if(mp[top]!=NULL && !visited[mp[top]]){
                q.push(mp[top]);
                visited[mp[top]]=true;
            }
            if(leaf(top)){
                continue;
            }
        }
        count++;
        }
        int n=q.size();
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};