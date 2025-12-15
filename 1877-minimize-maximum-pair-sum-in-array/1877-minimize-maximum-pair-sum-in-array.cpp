class Solution {
public:
    int minPairSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int res = INT_MIN;
        while(i<j){
            int sum = nums[i]+nums[j];
            res = max(res,sum);
            i++;
            j--;
        }
        return res;  
    }
};