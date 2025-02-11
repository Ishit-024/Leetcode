class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        // Start the recursive helper function
        helper(root, maxSum);
        return maxSum;
    }

private:
    int helper(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return 0;  // Return 0 for null nodes
        }

        // Recursively calculate the max path sum for left and right subtrees
        int left = max(helper(root->left, maxSum), 0);  // Only take positive values
        int right = max(helper(root->right, maxSum), 0);

        // Compute current path sum (node + left + right)
        int currentPathSum = root->val + left + right;

        // Update the global maxSum if we found a larger path sum
        maxSum = max(maxSum, currentPathSum);

        // Return the max path sum that includes this node
        return root->val + max(left, right);
    }
};
