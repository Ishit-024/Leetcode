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
bool isBalanced(TreeNode* root){
    int a=isb(root);
    if(a==-1){
        return false;
    }
    else{
        return true;
    }
}
    int isb(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int x=isb(root->left);
        if(x==-1){
            return -1;
        }
        int y=isb(root->right);
        if(y==-1){
            return -1;
        }
        if(abs(x-y)>1){
            return -1;
        }
        return 1+max(isb(root->left),isb(root->right));
    }
};