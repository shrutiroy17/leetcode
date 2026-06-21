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
    int findDepth(TreeNode* node){
        if(node==NULL) return 0;
        return 1+max(findDepth(node->left),findDepth(node->right));
    }
    TreeNode* fun(TreeNode* root,int depth,int maxD){
        if(root==NULL) return NULL;
        if(depth==maxD) return root;
        TreeNode* left = fun(root->left,depth+1,maxD);
        TreeNode* right = fun(root->right,depth+1,maxD);
        if(left && right) return root;
        return left?left:right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxD = findDepth(root);
        return fun(root,1,maxD);
    }
};