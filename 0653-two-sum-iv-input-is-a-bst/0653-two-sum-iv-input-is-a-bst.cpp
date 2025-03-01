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
    vector<int> inorder(TreeNode* root) {
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
        return v;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* node=root;
        vector<int>v=inorder(root);
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i]+v[j]==k){
                    return true;
                }
            }
        }
        return false;

        }
};