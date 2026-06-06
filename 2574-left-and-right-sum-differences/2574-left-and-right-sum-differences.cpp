class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> res;
        int left = 0 ;
        int sum = 0 ; 
        for(int i=0;i<n;i++){
            sum += nums[i] ;
        }
        for(int i=0;i<n;i++){
            int right = sum - nums[i] - left ;
            res.push_back(abs(left-right)) ;
            left += nums[i] ;
        }
        return res ;
    }
};