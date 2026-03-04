class Solution {
public:
    void helper(vector<int>& nums, int n, int idx, vector<int>& diary,
                vector<vector<int>>& res,vector<bool>& used) {
        if (idx == n) {
            res.push_back(diary);
            return;
        }
        for (int i = 0; i < n; i++) {
            if(used[i]) continue;
            used[i] = true;
            diary.push_back(nums[i]);
            helper(nums, n, idx + 1, diary, res,used);
            diary.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<int> diary;
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        helper(nums, n, idx, diary, res,used);
        return res;
    }
};