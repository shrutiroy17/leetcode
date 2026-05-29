class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int a1 = nums[left]*nums[left];
            int a2 = nums[right]*nums[right];
            if(a1>=a2){
                result[i] = a1;
                left++;
            }
            else{
                result[i] = a2;
                right--;
            }
        }
        return result;
    }
};