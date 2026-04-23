class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majEl = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                count = 1;
                majEl = nums[i];
            }
            else if(nums[i]==majEl) count++;
            else count--;
        }
        int res = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==majEl) res++;
        }
        if(res>n/2) return majEl;
        return -1;
    }
};