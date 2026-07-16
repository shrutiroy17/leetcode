class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums.size()==1 && nums[0]==1) return 0;
        if(nums.size()==1 && nums[0]==0) return 1;
        if(nums[0]!=0) return 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+1!=nums[i+1]) return nums[i]+1;
        }
        return nums[n-1]+1;
    }
};