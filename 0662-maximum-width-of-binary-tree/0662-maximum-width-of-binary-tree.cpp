class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) 
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            int minIdx = q.front().second; // To normalize indices
            int first, last;
            for (int i = 0; i < size; i++) {
                int cur_id = q.front().second - minIdx; // Normalize index
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = cur_id;
                if (i == size - 1) last = cur_id;
                if (node->left) 
                    q.push({node->left, (long long) 2 * cur_id});
                if (node->right) 
                    q.push({node->right,(long long) 2 * cur_id + 1});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
