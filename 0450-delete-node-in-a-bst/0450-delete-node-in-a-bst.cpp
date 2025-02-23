class Solution {
public:
    bool isleaf(TreeNode* root) {
        return (root->left == NULL && root->right == NULL);
    }

    bool found(TreeNode* root, int key) {
        while (root != NULL) {
            if (root->val == key) return true;
            root = (root->val > key) ? root->left : root->right;
        }
        return false;
    }

    TreeNode* helper(TreeNode* root) {
        TreeNode* temp = root->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = root->right;  
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) {
            if (isleaf(root)) return NULL;  // Case: Node is a leaf

            if (root->left == NULL) return root->right; // Case: Only right child
            if (root->right == NULL) return root->left; // Case: Only left child
            
            return helper(root); // Case: Two children
        }

        TreeNode* node = root;
        while (node != NULL) {
            if (node->left != NULL && node->left->val == key) {
                if (isleaf(node->left)) {
                    node->left = NULL;
                } else if (node->left->left == NULL) {
                    node->left = node->left->right;
                } else if (node->left->right == NULL) {
                    node->left = node->left->left;
                } else {
                    node->left = helper(node->left);
                }
                return root;
            } 
            else if (node->right != NULL && node->right->val == key) {
                if (isleaf(node->right)) {
                    node->right = NULL;
                } else if (node->right->left == NULL) {
                    node->right = node->right->right;
                } else if (node->right->right == NULL) {
                    node->right = node->right->left;
                } else {
                    node->right = helper(node->right);
                }
                return root;
            }

            node = (node->val > key) ? node->left : node->right;
        }

        return root;
    }
};
