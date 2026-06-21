class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size();
        if(costs[0]>coins) return 0;
        if(n==1 && costs[0]<=coins) return 1;
        int spent = costs[0] ; 
        int res = 1 ;
        for(int i=1;i<n;i++){
            if(spent+costs[i]<=coins){
                spent += costs[i];
                res++;
            }
        }
        return res;
    }
};