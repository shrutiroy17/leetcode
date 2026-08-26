class Solution {
public:
    int fun(vector<int>&p,int n,int i,int k,vector<vector<int>>&dp){
        if(i==n || k==0) return 0 ;
        if(dp[i][k]!=-1) return dp[i][k] ;
        if(k==2){
            int c1 = fun(p,n,i+1,k-1,dp) - p[i] ;
            int c2 = fun(p,n,i+1,k,dp) ;
            return dp[i][k] = max(c1,c2) ;
        }
        else{
            int c1 = fun(p,n,i+1,k-1,dp) + p[i] ;
            int c2 = fun(p,n,i+1,k,dp) ;
            return dp[i][k] = max(c1,c2) ;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        int k = 2 ;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        for(int i=0;i<=k;i++){
            dp[n][i] = 0 ;
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 0 ;
        }
        return fun(prices,n,0,k,dp) ;
    }
};