class Solution {
public:
    int fun(vector<vector<int>>& matrix, int n,int m,int g){
        int row = n-1;
        int col = 0;
        int count = 0;
        while(row>=0 && col<m){
            int el = matrix[row][col];
            if(el<=g){
                count += row+1;
                col++;
            }
            else row--;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        while(low<=high){
            int guess = (low+high)/2;
            int num = fun(matrix,n,m,guess);
            if(num<k) low = guess+1;
            else{
                res = guess;
                high = guess-1;
            }
        }
        return res;
    }
};