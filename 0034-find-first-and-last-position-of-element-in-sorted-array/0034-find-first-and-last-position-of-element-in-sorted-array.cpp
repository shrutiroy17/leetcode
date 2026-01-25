class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1 , f = -1 , l = -1;
        //finding first occurance
        while(low<=high){
            int guess = (high+low)/2;
            if(nums[guess]==target){
                f = guess;
                high = guess-1;
            }
            else if(nums[guess]>target){
                high = guess-1;
            }
            else{
                low = guess+1;
            }
        }
        low = 0;
        high = n-1;
        while(low<=high){
            int guess = (high+low)/2;
            if(nums[guess]==target){
                l = guess;
                low = guess+1;
            }
            else if(nums[guess]>target){
                high = guess-1;
            }
            else{
                low = guess+1;
            }
        }
        return {f,l};
    }
};