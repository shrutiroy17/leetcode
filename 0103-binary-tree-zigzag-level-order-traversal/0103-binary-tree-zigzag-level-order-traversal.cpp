/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == NULL) {
            return {};
        }
        q.push(root);
        int leftToRight = 1;
        while (!q.empty()) {
            int lvlSize = q.size();
            int first = 0;
            int last = lvlSize - 1;
            vector<int> temp(lvlSize);
            while (lvlSize--) {
                TreeNode* t = q.front();
                q.pop();
                if (leftToRight == 1) {
                    temp[first] = t->val;
                    first++;
                } else {
                    temp[last] = t->val;
                    last--;
                }
                if (t->left != NULL) {
                    q.push(t->left);
                }
                if (t->right != NULL) {
                    q.push(t->right);
                }
            }
            leftToRight = 1 - leftToRight;
            res.push_back(temp);
        }
        return res;
    }
};