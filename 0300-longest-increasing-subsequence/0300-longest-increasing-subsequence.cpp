class Solution {
public:
    int fun(vector<int>&a,int n,int i,int prev,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1 || a[i]>a[prev]){
            int c1 = fun(a,n,i+1,prev,dp);
            int c2 = 1 + fun(a,n,i+1,i,dp);
            return dp[i][prev+1] = max(c1,c2);
        }
        return dp[i][prev+1] = fun(a,n,i+1,prev,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int j=0;j<n;j++){
            dp[n][j] = 0 ;
        }
        int res = fun(nums,n,0,-1,dp);
        return res;
    }
};