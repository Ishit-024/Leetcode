class Solution {
public:
    bool isleaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }

    // Path from root to that leaf node
    void traverse(TreeNode* root, int num, int &sum) {
        if (root == NULL) return;

        num = num * 10 + root->val;  // Construct number

        if (isleaf(root)) {
            sum += num;  // Add to sum if it's a leaf node
            return;
        }

        traverse(root->left, num, sum);
        traverse(root->right, num, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traverse(root, 0, sum);
        return sum;
    }
};
