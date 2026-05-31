class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0 , high = 0 , res = -1;
        vector<int>f(2,0);
        while(high<n){
            f[nums[high]]++;
            while(f[0]>k){
                f[nums[low]]--;
                low++;
            }
            res = max(res,high-low+1);
            high++;
        }
        return res;
    }
};