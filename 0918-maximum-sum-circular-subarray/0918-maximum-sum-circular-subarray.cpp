class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxBest = 0;
        int resMax = nums[0];
        int minBest = nums[0];
        int resMin = nums[0];
        int n = nums.size();
        int total = nums[0];
        for(int i=1;i<n;i++){
            total += nums[i];
            maxBest = max(maxBest+nums[i],nums[i]);
            resMax = max(resMax,maxBest);
            minBest = min(minBest+nums[i],nums[i]);
            resMin = min(resMin,minBest);
        }
        if(resMax<0){
            return resMax;
        }
        return max(total-resMin,resMax);
    }
};