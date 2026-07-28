class Solution {
public:
    unordered_map<int,int>dp;
    int climbStairs(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp.find(n)!=dp.end()) return dp[n];
        int ans1 = climbStairs(n-1);
        int ans2 = climbStairs(n-2);
        int ans = ans1+ans2;
        dp[n] = ans;
        return ans;
    }
};