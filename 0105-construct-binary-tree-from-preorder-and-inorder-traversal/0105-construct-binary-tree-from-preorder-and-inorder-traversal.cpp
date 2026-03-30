class Solution {
public:
    unordered_map<int,int> in;
    int idx = 0;

    TreeNode* fun(vector<int>& preorder, int low, int high) {
        if (low > high) return NULL;

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        int id = in[node->val];

        node->left = fun(preorder, low, id - 1);
        node->right = fun(preorder, id + 1, high);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }

        return fun(preorder, 0, inorder.size() - 1);
    }
};