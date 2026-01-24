class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int>mpp; //sum->count
        mpp[0] = 1;
        int count = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int ques = sum-goal;
            if(mpp.find(ques)!=mpp.end()){
                count += mpp[ques];
            }
            mpp[sum]++;
        }
        return count;
    }
};