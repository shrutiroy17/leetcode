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
    int height(TreeNode* node){
        if(node==NULL) return 0;
        int leftH = height(node->left);
        int rightH = height(node->right);
        return 1+max(leftH,rightH);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return root;
        int leftH = height(root->left);
        int rightH = height(root->right);
        if(leftH==rightH) return root;
        else if(leftH>rightH) return lcaDeepestLeaves(root->left);
        else
        return lcaDeepestLeaves(root->right);
    }
};