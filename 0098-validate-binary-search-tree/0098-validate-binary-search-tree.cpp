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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        if(root==NULL){
            return v;
        }
       TreeNode* curr = root;
        while ( !s.empty() || curr!=NULL) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            // Process the top node
            curr = s.top();
            s.pop();
            v.push_back(curr->val);

            // Move to the right subtree
            curr = curr->right;
        }
        for(int num:v){
            cout << num;
        }
        return v;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        vector<int>v=inorderTraversal(root);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};