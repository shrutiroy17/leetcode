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
    vector<vector<int>> res;
    void fun(TreeNode* root, int sum,int t,vector<int>&temp){
        if(root==NULL) return;
        sum += root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==t){
                res.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        fun(root->left,sum,t,temp);
        fun(root->right,sum,t,temp);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>temp;
        fun(root,sum,targetSum,temp);
        return res;
    }
};