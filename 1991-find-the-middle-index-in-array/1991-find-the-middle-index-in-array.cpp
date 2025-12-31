class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int sum = 0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        int left = 0;
        for(int i=0;i<n;i++){
            int right = sum-nums[i]-left;
            if(left==right) return i;
            left+=nums[i];
        }
        return -1;
    }
};