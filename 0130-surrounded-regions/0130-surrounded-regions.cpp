class Solution {
public:
    int x[4] = {0,0,-1,1};
    int y[4] = {-1,1,0,0};
    bool isValid(int i , int j , int n, int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& board,int i,int j,int n,int m){
        board[i][j] = '#';
        for(int k=0;k<4;k++){
            int row = i + x[k];
            int col = j + y[k];
            if(isValid(row,col,n,m) && board[row][col]=='O'){
                dfs(board,row,col,n,m);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(board,0,j,n,m);
        }
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O') dfs(board,n-1,j,n,m);
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(board,i,0,n,m);
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O') dfs(board,i,m-1,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
        return;
    }
};