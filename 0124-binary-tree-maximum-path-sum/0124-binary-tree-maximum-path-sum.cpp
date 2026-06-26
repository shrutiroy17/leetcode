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
    int ans = INT_MIN;
    int solve(TreeNode* node){
        if(!node) return 0;
        int leftMax = max(0,solve(node->left));
        int rightMax = max(0,solve(node->right));
        ans = max(ans,node->val+leftMax+rightMax);
        return node->val+max(leftMax,rightMax);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};