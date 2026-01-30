class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1;
        int col = 0;
        while(row>=0 && col<m){
            int el = matrix[row][col];
            if(el==target){
                return true;
            }
            else if(el>target) row--;
            else col++;
        }
        return false;
    }
};