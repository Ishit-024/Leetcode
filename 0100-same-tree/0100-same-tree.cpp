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
       vector<int> preorder(TreeNode*root){
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* root=st.top();
            st.pop();
            if(root->right!=NULL){
                st.push(root->right);
            }
            if(root->right==NULL){
                ans.push_back(root->val);
            }
            if(root->left!=NULL){
                st.push(root->left);
            }
            ans.push_back(root->val);
        }
        return ans;
    }
    // vector<int> levelOrder(TreeNode* root){
    //     vector<int>v;
    //     if(root==NULL){
    //         return v;
    //     }
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         TreeNode*top=q.front();
    //         q.pop();
    //         v.push_back(top->val);
    //         if(top->left!=NULL){
    //             q.push(top->left);
    //         }
    //         if(top->left==NULL){
    //             q.push(NULL);
    //         }
    //         if(top->right!=NULL){
    //             q.push(top->right);
    //         }
    //         if(top->right==NULL){
    //             q.push(NULL);
    //         }
    //     }
    //     for(int i:v){
    //         cout << i << endl;
    //     }
    //     return v;
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       vector<int>v=preorder(p);
       vector<int>z=preorder(q);
       if(v.size()!=z.size()){
        return false;
       }
       for(int i=0;i<v.size();i++){
        if(v[i]!=z[i]){
            return false;
        }
       }
       return true;
    }
};