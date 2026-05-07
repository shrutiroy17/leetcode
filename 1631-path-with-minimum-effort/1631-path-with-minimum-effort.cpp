class Solution {
public:
    bool isValid(int i,int j, int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
                priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        int x[4] = {0,0,-1,1};
        int y[4] = {1,-1,0,0};
        pq.push({0,{0,0}});
        res[0][0] = 0;
        while(!pq.empty()){
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            int d = p.first;
            int i = p.second.first;
            int j = p.second.second;
            
            if (i == n - 1 && j == m - 1) return d;
            for(int k=0;k<4;k++){
                int r = i+x[k];
                int c = j+y[k];
                if(!isValid(r,c,n,m)) continue;
                int absDiff = abs(heights[i][j] - heights[r][c]);
                int newWt = max(absDiff,d);
                if(newWt<res[r][c]){
                    res[r][c] = newWt;
                    pq.push({newWt,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};