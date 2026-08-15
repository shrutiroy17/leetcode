class Solution {
public:
    int fun(vector<int>&a,int n,vector<vector<int>>&dp){
        for(int i=n-1;i>=0;i--){
            for(int j=-1;j<n;j++){
                if(j==-1 || a[i]>a[j]){
                    dp[i][j+1] = max(dp[i+1][j+1],1+dp[i+1][i+1]);
                }
                else{
                    dp[i][j+1] = dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int res = fun(nums,n,dp);
        return res;
    }
};