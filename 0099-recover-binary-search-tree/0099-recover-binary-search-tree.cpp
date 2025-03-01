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
    
    vector<TreeNode*> inorder(TreeNode* root) {
        vector<TreeNode*> v;
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
            v.push_back(curr);

            // Move to the right subtree
            curr = curr->right;
        }
        return v;
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>v=inorder(root);
        vector<int>a;
        for(int i=0;i<v.size();i++){
            a.push_back(v[i]->val);
        }
        std::sort(a.begin(),a.end());
        for(int i=0;i<v.size();i++){
            if(v[i]->val!=a[i]){
                v[i]->val=a[i];
            }
        }
    }
};