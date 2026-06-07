class Solution {
public:
    bool possible(vector<int>&nums,int guess,int k){
        //no subarray is allowed to have a sum>guess
        int sum = 0,count=1;
        for(int x:nums){
            if(x+sum<=guess){
                sum += x;
            }
            else{
                count++;
                sum = x;
                if(count>k) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int res = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(nums,mid,k)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};