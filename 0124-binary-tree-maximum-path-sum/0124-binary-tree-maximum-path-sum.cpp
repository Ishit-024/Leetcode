class Solution {
    int maxi = INT_MIN;
public:
    bool leaf(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        return false;
    }

    int maxPathSum(TreeNode* root) {
        solve(root);         // call the helper function
        return maxi;         // return the final max path sum
    }

    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        else if (leaf(root)) {
            maxi = max(maxi, root->val);  // Update maxi in case it's the only node
            return root->val;
        }

        int l = max(0, solve(root->left));
        int r = max(0, solve(root->right));
        maxi = max(maxi, l + r + root->val);
        return root->val + max(l, r);
    }
};
