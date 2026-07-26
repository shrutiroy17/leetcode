class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxNum = nums[n-1];
        int secondMax = nums[n-2];
        int thirdMax = nums[n-3];
        int ans1 = maxNum*secondMax*thirdMax;
        int ans2 = nums[0]*nums[1]*maxNum;
        return max(ans1,ans2);
    }
};