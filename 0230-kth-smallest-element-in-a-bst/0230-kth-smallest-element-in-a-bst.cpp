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
    int count = 0 , res = 0 ;
    void inOrder(TreeNode* node,int k){
        if(!node) return;
        inOrder(node->left,k);
        count++;
        if(count==k){
            res = node->val;
            return;
        }
        inOrder(node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root,k);
        return res;
    }
};