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
    int sum = 0;
    void fun(TreeNode* root,string num){
        if(root==NULL) return;
        num.push_back(root->val + '0');
        if(root->left==NULL && root->right==NULL){
            sum += stoi(num);
            return;
        }
        fun(root->left,num);
        fun(root->right,num);
        return;
    }
    int sumNumbers(TreeNode* root) {
        string num = "";
        fun(root,num);
        return sum;
    }
};