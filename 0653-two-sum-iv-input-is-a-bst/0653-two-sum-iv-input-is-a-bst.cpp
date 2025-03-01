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
class BST{
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    public:
    BST(TreeNode* root){
        fill1(root);
        fill2(root);
    }
    int next(){
        TreeNode* x=st1.top();
        st1.pop();
        if(x->right!=NULL){
            fill1(x->right);
        }
        return x->val;
    }
    int prev(){
        TreeNode* y=st2.top();
        st2.pop();
        if(y->left!=NULL){
            fill2(y->left);
        }
        return y->val;
    }
    private:
    void fill1(TreeNode* root){
        while(root!=NULL){
            st1.push(root);
            root=root->left;
        }
    }
    void fill2(TreeNode* root){
        while(root!=NULL){
            st2.push(root);
            root=root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BST* b=new BST(root);
        if(root==NULL){
            return false;
        }
        int x=b->next();
        int y=b->prev();
        while(x<y){
        if(x+y==k){
            return true;
        }
        else if(x+y<k){
            x=b->next();
        }
        else{
            y=b->prev();
        }
        }
        return false;
    }
};