/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL){
        return NULL;
    }
    TreeNode*x;
    while(root!=NULL){
        if(p->val>root->val && q->val <root->val || p->val<root->val && q->val > root->val){
            return root;
        }
        else if(p->val<root->val && q->val < root->val){
            root=root->left;
        }
        else if(p->val>root->val && q->val>root->val){
            root=root->right;
        }
        else if(p->val==root->val){
            x=root;
            break;
        }
        else if(q->val==root->val){
            x=root;
            break;
        }
    }
    return x;
}
};