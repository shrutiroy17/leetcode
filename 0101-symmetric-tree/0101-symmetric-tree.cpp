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
    bool isPossible(TreeNode* n1,TreeNode* n2){
        if(n1==NULL && n2==NULL) return true;
        if(n1==NULL || n2==NULL) return false;
        if(n1->val!=n2->val) return false;
        bool ans1 = isPossible(n1->left,n2->right);
        bool ans2 = isPossible(n1->right,n2->left);
        if(ans1 && ans2) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        bool answer = isPossible(root->left,root->right);
        return answer;
    }
};