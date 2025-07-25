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
bool leaf(TreeNode* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}
bool isBalanced(TreeNode* root){
    if(root==NULL){
        return true;
    }
    else if(leaf(root)){
        return true;
    }
    else{
        int x=checkht(root->left);
        int y=checkht(root->right);
        if(abs(x-y)>1){
            return false;
        }
        bool a=isBalanced(root->left);
        bool b=isBalanced(root->right);
        if(a==false || b==false){
            return false;
        }
    }
        return true;
}
int checkht(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    else if(leaf(root)){
        return 1;
    }
    else{
        return 1+max(checkht(root->left),checkht(root->right));
    }
}
};