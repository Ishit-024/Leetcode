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
    TreeNode* levelOrder(TreeNode* root,int x){
        queue<TreeNode*>q;
        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top->val==x){
                return top;
                break; 
            }
            if(top->left!=NULL){
                q.push(top->left);
            }
            if(top->right!=NULL){
                q.push(top->right);
            }
        }
        return root;
    }
    bool traverse(TreeNode *root,vector<int>&a,int t){
	if(root==NULL){
		return false;
	}
	a.push_back(root->val);
	if(root->val==t){
		return true;
	}
	bool x=traverse(root->left,a,t);
	bool y=traverse(root->right,a,t);
	if(x || y){
		return true;
	}
	else{
		a.pop_back();
		return false;
	}
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<int>a;
    vector<int>b;
	traverse(root,a,p->val);
    traverse(root,b,q->val);
    int c=INT_MIN;
    for(int num1:a){
        for(int num2:b){
            if(num1==num2){
                c=num1;
                }
            }
        }
    TreeNode* t=levelOrder(root,c);
    return t;
    }
};