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
    vector<int> levelOrder(TreeNode* root){
        vector<int>v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode*top=q.front();
            q.pop();
            v.push_back(top->val);
            if(top->left!=NULL){
                q.push(top->left);
            }
            if(top->left==NULL){
                v.push_back(top->val);
            }
            if(top->right!=NULL){
                q.push(top->right);
            }
            if(top->right==NULL){
                v.push_back(100);
            }
        }
       return v;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL){
        return true;
    }
    if(p==NULL && q!=NULL || q==NULL && p!=NULL){
        return false;
    }
    if(p->val!=q->val){
        return false;
    }
    return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right)); 
}
};