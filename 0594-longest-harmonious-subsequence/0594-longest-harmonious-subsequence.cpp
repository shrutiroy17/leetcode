class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            int el = nums[i];
            int next = el+1;
            if(mpp.find(next)!=mpp.end()){
                int len = mpp[el]+mpp[next];
                res = max(res,len);
            }
        }
        return res;
    }
};