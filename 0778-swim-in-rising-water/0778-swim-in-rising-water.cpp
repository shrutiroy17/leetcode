class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};
        res[0][0] = grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            int d = p.first;
            int r = p.second.first;
            int c = p.second.second;
            if(d>res[r][c]) continue;
            for(int k=0;k<4;k++){
                int row = r + x[k];
                int col = c + y[k];
                if(!isValid(row,col,n,m)) continue;
                int nWeight = max(d,grid[row][col]);
                if(nWeight<res[row][col]){
                    res[row][col] = nWeight;
                    pq.push({nWeight,{row,col}});
                }
            }
        }
        return res[n-1][m-1];
    }
};