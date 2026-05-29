class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int i = 2;
        int j = 2;
        while(j<n){
            //invalid condition -> third occurance
            if(nums[j]!=nums[i-2]){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};