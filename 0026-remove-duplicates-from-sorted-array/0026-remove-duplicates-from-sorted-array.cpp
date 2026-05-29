class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int i = 0 , j = 1;
        while(j<n){
            if(nums[j]!=nums[i]){
                i = i+1;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        return (i+1);
    }
};