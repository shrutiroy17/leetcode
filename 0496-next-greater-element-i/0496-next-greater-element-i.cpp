class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //pre computer for nums2
        stack<int>st;
        st.push(nums2[n2-1]);
        vector<int>nums2Ans(n2);
        nums2Ans[n2-1] = -1;
        for(int i=n2-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()) nums2Ans[i]=-1;
            else  nums2Ans[i]=st.top();
            st.push(nums2[i]);
        }
        //now map from nums1 
        vector<int>res(n1);
        unordered_map<int,int>mpp;
        for(int i=0;i<n2;i++){
            mpp[nums2[i]]=i;
        }
        for(int i=0;i<n1;i++){
            res[i] = nums2Ans[mpp[nums1[i]]];
        }
        return res;
    }
};