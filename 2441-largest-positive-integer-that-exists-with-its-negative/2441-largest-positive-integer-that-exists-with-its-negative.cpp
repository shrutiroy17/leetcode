class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = -1;
        unordered_map<int,int>mpp;
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            int el = -maxi;
            if(mpp.find(el)!=mpp.end()){
                res = max(res,maxi);
            }
            mpp[nums[i]]++;
        }
        return res;
    }
};