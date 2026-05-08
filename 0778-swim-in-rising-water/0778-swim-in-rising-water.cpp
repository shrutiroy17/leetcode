class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int x[4] = {0,0,-1,1};
    int y[4] = {-1,1,0,0};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        res[0][0] = grid[0][0];
        
priority_queue<
    pair<int, pair<int, int>>, 
    vector<pair<int, pair<int, int>>>, 
    greater<pair<int, pair<int, int>>>
> pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            int wt = p.first;
            int i = p.second.first;
            int j = p.second.second;
            for(int k=0;k<4;k++){
                int r = i+x[k];
                int c = j+y[k];
                if(!isValid(r,c,n,m)) continue;
                int newAns = max(wt,grid[r][c]);
                if(newAns<res[r][c]){
                    res[r][c] = newAns;
                    pq.push({newAns,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};