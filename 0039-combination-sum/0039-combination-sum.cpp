class Solution {
public:
    void helper(vector<int>& candidates,int n,int idx,vector<int>&diary,int sum,vector<vector<int>>&res,int target){
        if (sum == target) {
            res.push_back(diary);
            return;
        }
        if (sum > target || idx == n)
            return;
        //exclude
        helper(candidates,n,idx+1,diary,sum,res,target);
        //include
        if(sum+candidates[idx]<=target){
            diary.push_back(candidates[idx]);
            sum += candidates[idx];
            helper(candidates,n,idx,diary,sum,res,target);
            diary.pop_back();
            sum -= candidates[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int idx = 0;
        vector<int>diary;
        vector<vector<int>>res;
        int sum = 0;
        helper(candidates,n,idx,diary,sum,res,target);
        return res;
    }
};