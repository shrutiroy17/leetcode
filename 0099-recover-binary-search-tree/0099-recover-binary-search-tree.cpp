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
    void markWrong(TreeNode* &node,TreeNode* &prev,TreeNode* &start,TreeNode* &end){
        if(!node) return;
        markWrong(node->left,prev,start,end);
        if(prev){
            if(node->val<prev->val){
                if(!start){
                    start = prev;
                }
                end = node;
            }
        }
        prev = node;
        markWrong(node->right,prev,start,end);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* start = nullptr;
        TreeNode* end = nullptr;
        markWrong(root,prev,start,end);
        swap(start->val,end->val);
        return;
    }
};