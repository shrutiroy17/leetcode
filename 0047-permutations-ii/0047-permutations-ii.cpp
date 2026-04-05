class Solution {
public:
    void fun(vector<int>& nums,int n,int idx,vector<int>& diary,vector<vector<int>>&res, vector<bool>&used){
        if(idx==n){
            res.push_back(diary);
            return;
        }
        for(int i=0;i<n;i++){
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
                continue;
            }
            diary.push_back(nums[i]);
            used[i] = true;
            fun(nums,n,idx+1,diary,res,used);
            diary.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>diary;
        int idx = 0;
        vector<vector<int>> res;
        vector<bool>used(n,false);
        fun(nums,n,idx,diary,res,used);
        return res;
    }
};