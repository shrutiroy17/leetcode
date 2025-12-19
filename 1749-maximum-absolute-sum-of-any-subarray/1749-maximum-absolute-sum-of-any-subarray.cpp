class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return abs(nums[0]);
        }
        int maxBest = nums[0];
        int minBest = nums[0];
        int res = nums[0];
        for(int i=1;i<n;i++){
            maxBest = max(maxBest+nums[i],nums[i]);
            minBest = min(minBest+nums[i],nums[i]);
            res = max(res,max(abs(maxBest),abs(minBest)));
        }
        return res;
    }
};