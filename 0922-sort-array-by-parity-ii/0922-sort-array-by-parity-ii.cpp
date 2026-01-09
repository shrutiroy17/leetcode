class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while (i < n && j < n){
            if( (i%2==0 && nums[i]%2!=0) && (j%2!=0 && nums[j]%2==0)){
                swap(nums[i],nums[j]);
            }
            if((i<n && i%2==0 && nums[i]%2==0)) i = i+2;
            if(j<n && (j%2!=0 && nums[j]%2!=0)) j = j+2;
        }
        return nums;
    }
};