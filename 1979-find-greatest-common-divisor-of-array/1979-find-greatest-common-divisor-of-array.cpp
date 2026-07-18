class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNum = *min_element(nums.begin(),nums.end());
        int maxNum = *max_element(nums.begin(),nums.end());
        for(int i=minNum;i>=1;i--){
            if(minNum%i==0 && maxNum%i==0){
                return i;
            }
        }
        return -1;
    }
};