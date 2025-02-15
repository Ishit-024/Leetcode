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
int sum;
class Solution {
public:
    bool isleaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    bool traverse(TreeNode* root,int targetSum,int currsum){
        if(root==NULL){
            return false;
        }
        currsum=currsum+root->val;
        // if(currsum>targetSum){
        //     // currsum=currsum-root->val;
        //     return false;
        // }
        if(currsum==targetSum && isleaf(root)){
            return true;
        }
       bool x=traverse(root->left,targetSum,currsum);
       bool y=traverse(root->right,targetSum,currsum);
       if(x || y){
        return true;
       }
       else{
        return false;
       }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        // if(root->left=
        bool x=traverse(root,targetSum,0);
        return x;
    }
};