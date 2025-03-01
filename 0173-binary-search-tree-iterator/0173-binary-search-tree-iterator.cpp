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
class BSTIterator {
    stack<TreeNode*>mystack;
public:
    BSTIterator(TreeNode* root) {
        fillin(root);
    }
    int next() {
       TreeNode* node=mystack.top();
       mystack.pop();
       if(node->right!=NULL){
       fillin(node->right);
       }
    return node->val;
    }
    bool hasNext() {
        return !(mystack.empty()) ;
           }
    private:
    void fillin(TreeNode* root){
        while(root!=NULL){
            mystack.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */