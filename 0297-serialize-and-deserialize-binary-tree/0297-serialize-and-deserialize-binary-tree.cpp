/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL){
            return s;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top==NULL){
                s.append("#,");
            }
            else{
            s.append(to_string(top->val)+",");
            q.push(top->left);
            q.push(top->right);
        }
        }
        // cout << s << endl;
        return s;
    }
TreeNode* deserialize(string data) {
    if (data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ','); // Read the first value

        TreeNode* root = new TreeNode(stoi(str)); // Create root node
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Process left child
            getline(s, str, ',');
            if (str == "#") {
                node->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Process right child
            getline(s, str, ',');
            if (str == "#") {
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));