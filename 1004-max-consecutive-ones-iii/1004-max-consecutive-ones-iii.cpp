class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0 , high = 0 ;
        int res = INT_MIN ;
        int count0 = 0 ;
        while(high<n){
            if(nums[high]==0) count0++;
            while(count0>k){
                if(nums[low]==0) count0--;
                low++;
            }
            res = max(res,high-low+1);
            high++;
        }
        return res;
    }
};