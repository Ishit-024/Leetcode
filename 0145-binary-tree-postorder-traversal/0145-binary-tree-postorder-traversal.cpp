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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*> st1,st2;
        TreeNode* x=root;
        if(root==NULL){
            return v;
        }
        st1.push(x);
        while(!st1.empty()){
            x=st1.top();
            st1.pop();
            st2.push(x);
            if(x->left!=NULL){
                st1.push(x->left);
            }
            if(x->right!=NULL){
                st1.push(x->right);
            }
        }
        while(!st2.empty()){
            TreeNode* temp=st2.top();
            st2.pop();
            v.push_back(temp->val);
        }
        return v;
    }
};