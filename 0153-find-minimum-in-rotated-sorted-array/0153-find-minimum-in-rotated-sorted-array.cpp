class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans = 0;
        while(low<=high){
            int guess = (high+low)/2;
            if(nums[guess]>nums[n-1]){
                low = guess+1;
            }
            else{
                ans = guess;
                high = guess-1;
            }
        }
        return nums[ans];
    }
};