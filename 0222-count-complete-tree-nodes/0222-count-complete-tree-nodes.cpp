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
    int levelOrder(TreeNode* root){
        queue<TreeNode*>q;
        if(root==NULL){
            return 0;
        }
        q.push(root);
        int count=0;
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            count++;
            if(top->left!=NULL){
                q.push(top->left);
            }
            if(top->right!=NULL){
                q.push(top->right);
            }
            }
            return count;
        }
    int countNodes(TreeNode* root) {
        int x=levelOrder(root);
        return x;
    }
};