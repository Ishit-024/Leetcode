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
    bool isleaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    int ceilis(TreeNode* root,int val){
        if(root==NULL){
            return -1;
        }
        int ceil=-1;
        while(root!=NULL){
            if(root->val==val){
                return val;
            }
            else if(root->val>val){
                ceil=root->val;
                root=root->left;
            }
            else{
                root=root->right;
            }
            }
            return ceil;
    }
    int flooris(TreeNode* root,int val){
        if(root==NULL){
            return -1;
        }
        int floor=-1;
        while(root!=NULL){
            if(root->val==val){
                return val;
            }
            else if(root->val<val){
                floor=root->val;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return floor;
    }   
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* x=new TreeNode(val);
            return x;
        }
        int ceil=ceilis(root,val);
        int floor=flooris(root,val);
        TreeNode* node=root;
            while(node!=NULL){
            if(node->val==ceil && ceil!=-1){
                TreeNode* n=node->left;
                TreeNode* x=new TreeNode(val);
                node->left=x;
                x->left=n;
                break;
            }
            else if(ceil==-1 && floor!=-1){
                if(node->val==floor){
                    TreeNode* x=new TreeNode(val);
                    node->right=x;
                    x->left=NULL;
                    x->right=NULL;
                    break;
                }
            }
            if(node->val>val){
                node=node->left;
            }
            if(node->val<val){
                node=node->right;
            }
            }
            return root;
            }
};