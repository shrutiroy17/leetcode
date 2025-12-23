class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int count = 0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum = sum+nums[i];
            int rawRem = sum%k;
            int rem = (rawRem+k)%k;
            if(mpp.find(rem)!=mpp.end()){
                count = count+mpp[rem];
            }
            mpp[rem]++;
        }
        return count;
    }
};