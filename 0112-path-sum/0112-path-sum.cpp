class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return (root->left == nullptr && root->right == nullptr);
    }

    bool traverse(TreeNode* root, int targetSum, int currentSum) {
        if (root == nullptr) {
            return false;
        }
        
        currentSum += root->val;  // Use root->val directly, no need for abs()

        // If it's a leaf node and the sum matches, return true
        if (isLeaf(root) && currentSum == targetSum) {
            return true;
        }

        // Recursively check left and right subtrees
        bool leftPath = traverse(root->left, targetSum, currentSum);
        bool rightPath = traverse(root->right, targetSum, currentSum);

        return leftPath || rightPath;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root, targetSum, 0);
    }
};