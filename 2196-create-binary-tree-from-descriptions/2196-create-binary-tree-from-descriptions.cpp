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
    //map stores node->node info , this helps to access fastly
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode* >mpp;
        unordered_set<int>st;
        for(auto d:descriptions ){
            int parent = d[0] , child = d[1] , isLeft = d[2] ; 
            if (!mpp.count(parent))
                mpp[parent] = new TreeNode(parent);

            if (!mpp.count(child))
                mpp[child] = new TreeNode(child);
            if(isLeft){
                mpp[parent]->left = mpp[child];
            }
            else{
                mpp[parent]->right = mpp[child];
            }
            st.insert(child);
        }
        for (auto d : descriptions) {
            int parent = d[0];

            if (!st.count(parent))
                return mpp[parent];
        }

        return NULL;
    }
};