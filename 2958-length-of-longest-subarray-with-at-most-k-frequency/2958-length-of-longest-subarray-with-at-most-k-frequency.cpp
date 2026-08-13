class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        int low = 0 , high = 0 , res = -1 ;
        while(high<n){
            mpp[nums[high]]++;
            while(mpp[nums[high]]>k){
                mpp[nums[low]]--;
                if(mpp[nums[low]]==0){
                    mpp.erase(nums[low]);
                }
                low++;
            }
            res = max(res,high-low+1);
            high++;
        }
        return res;
    }
};