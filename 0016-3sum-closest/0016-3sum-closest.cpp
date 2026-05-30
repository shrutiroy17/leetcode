class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closest = INT_MAX;
        int res = -1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int diff = abs(target-sum);
                if(diff<closest){
                    closest = diff;
                    res = sum;
                }
                if(sum<target) j++;
                else k--;
            }
        }
        return res;
    }
};