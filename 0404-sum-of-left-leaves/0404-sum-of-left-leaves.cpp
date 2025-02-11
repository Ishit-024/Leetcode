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
bool leaf(TreeNode*root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
    }
vector<int> preorder(TreeNode *root)
{
    vector<int>v;
    if(root==NULL){
        return v;
    }
    stack<TreeNode *>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* top=st.top();
        st.pop();
        if(top->right!=NULL){
            st.push(top->right);
        }
        if(top->left!=NULL){
            st.push(top->left);
        }
        if(top->left!=NULL && top->right==NULL && leaf(top->left)){
            v.push_back(top->left->val);
        }
        if(top->left!=NULL && top->right!=NULL && leaf(top->left)){
            v.push_back(top->left->val);
        }
    }
    return v;
    }
int sumOfLeftLeaves(TreeNode* root) {
        vector<int>vx=preorder(root);
        int sum=0;
        for(int num:vx){
            sum=sum+num;
        }
        return sum;
    }
};