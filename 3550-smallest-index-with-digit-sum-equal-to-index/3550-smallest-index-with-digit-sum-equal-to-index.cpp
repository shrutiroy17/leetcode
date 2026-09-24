class Solution {
public:
    int fun(int n){
        int sum = 0 ;
        while(n>0){
            int rem = n%10;
            sum += rem;
            n = n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]==0) return 0 ;
        for(int i=1;i<n;i++){
            int sum = fun(nums[i]);
            if(sum==i) return i ;
        }
        return -1 ;
    }
};