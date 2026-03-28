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
    TreeNode* prev = NULL;
    TreeNode* g11 = NULL;
    TreeNode* g12 = NULL;
    TreeNode* g21 = NULL;
    TreeNode* g22 = NULL;
    int galat = 0;
    void fun(TreeNode* root){
        if(root==NULL) return;
        fun(root->left);
        if(prev==NULL) prev = root;
        else{
            if(root->val<=prev->val){
                if(galat==0){
                    g11 = prev;
                    g12 = root; 
                    galat++;
                }
                else{
                    g21 = prev;
                    g22 = root;
                    galat++;
                }
            }
            prev = root;
        }
        fun(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        fun(root);
        if(galat==1){
            swap(g11->val,g12->val);
        }
        else{
            swap(g11->val,g22->val);
        }
    }
};