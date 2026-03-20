class Solution {
public:
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;
    TreeNode* getSmallest() {
        if (asc.empty()) return NULL;
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightChild = small->right;
        while (rightChild) {
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;
    }
    TreeNode* getLargest() {
        if (desc.empty()) return NULL;
        TreeNode* big = desc.top();
        desc.pop();
        TreeNode* leftChild = big->left;
        while (leftChild) {
            desc.push(leftChild);
            leftChild = leftChild->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        TreeNode* t = root;
        while (t) {
            asc.push(t);
            t = t->left;
        }
        t = root;
        while (t) {
            desc.push(t);
            t = t->right;
        }
        TreeNode* i = getSmallest();
        TreeNode* j = getLargest();
        while (i && j && i != j && i->val < j->val) {
            int sum = i->val + j->val;
            if (sum == k) return true;
            else if (sum > k)
                j = getLargest();
            else
                i = getSmallest();
        }
        return false;
    }
};