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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode* >q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int levelSize = q.size();
            vector<int>temp(levelSize);
            int front = 0;
            int last = levelSize-1;
            while(levelSize--){
                TreeNode* t = q.front();
                q.pop();
                if(leftToRight){
                    temp[front] = t->val;
                    front++;
                }
                else{
                    temp[last] = t->val;
                    last--;
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            leftToRight = !leftToRight;
            res.push_back(temp);
        }
        return res;
    }
};