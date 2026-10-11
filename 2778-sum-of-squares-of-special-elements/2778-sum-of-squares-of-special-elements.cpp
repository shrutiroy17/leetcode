class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ;
        for(int i=0;i<n;i++){
            int newI = i+1;
            if(n%newI==0){
                int squareNum = nums[i]*nums[i];
                sum += squareNum;
            }
        }
        return sum;
    }
};