class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i])
            st.pop();
            if(!st.empty()){
                ans[i]=st.top();
            }
            else{
                ans[i]=-1;
            }
            st.push(nums[i]);
        }
        return ans;
    }
};