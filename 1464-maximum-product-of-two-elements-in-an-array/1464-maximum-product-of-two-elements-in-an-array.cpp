class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum = 0;
        int secondMaxNum = 0; 
        for (int value : nums) {
            if (value > maxNum) {
                secondMaxNum = maxNum; 
                maxNum = value; 
            } 
            else if (value > secondMaxNum) {
                secondMaxNum = value; 
            }
        }
        return (maxNum - 1) * (secondMaxNum - 1);
    }
};