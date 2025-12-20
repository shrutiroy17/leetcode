class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int ans = 0;
        int sum = 0;
        for(int high = 0;high<nums.size();high++){
            sum += nums[high];
            while(sum+k<high-low+1){
                sum = sum-nums[low];
                low++;
            }
            ans = max(ans,high-low+1);
        }
        return ans;
    }
};