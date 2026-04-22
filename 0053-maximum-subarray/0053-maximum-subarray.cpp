class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int sum=nums[0];
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i++){
            int val1 = sum+nums[i];
            int val2 = nums[i];
            sum = max(val1,val2);
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};