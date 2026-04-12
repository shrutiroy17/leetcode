class Solution {
public:
    vector<int>x ={-1,1,0,0};
    vector<int>y = {0,0,-1,1};
    bool isValid(int r,int c,int n,int m){
        if(r<0 || r>=n || c<0 || c>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0, i = 0 , j = 0 , time = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j] = -2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh>0){
            time++;
            int s = q.size();
            while(s--){
                pair<int,int>p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                for(int k=0;k<4;k++){
                    int row = r + x[k];
                    int col = c + y[k];
                    if(isValid(row,col,n,m) && grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col] = -2;
                        fresh--;
                    }
                }
            }
        }
        if(fresh>0) return -1;
        return time;
    }
};