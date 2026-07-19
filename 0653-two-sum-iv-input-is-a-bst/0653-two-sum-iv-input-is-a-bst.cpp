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
    vector<int>treeList;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        treeList.push_back(root->val);
        inorder(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        //find inorder traversal -> resultanat array is sorted list
        inorder(root);
        int i = 0 , j = treeList.size()-1;
        while(i<j){
            int sum = treeList[i]+treeList[j];
            if(sum==k){
                return true;
            }
            else if(sum>k) j--;
            else i++;
        }
        return false;
    }
};