class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0;
        int count1 = 0;
        int ans = 0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(nums[i]==0) count0++;
            else
            count1++;
            int diff = count0-count1;
            if(diff==0){
                ans = max(ans,i+1);
            }
            else if(mpp.find(diff)==mpp.end()){
                mpp[diff]=i;
            }
            else{
                ans = max(ans,i-mpp[diff]);
            }
        }
        return ans;
    }
};