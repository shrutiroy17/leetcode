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
    int getHeight(TreeNode* node){
        if(node==NULL) return 0;
        int lh = getHeight(node->left);
        int rh = getHeight(node->right);
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        if (abs(leftH-rightH)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};