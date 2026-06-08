class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //guess the row value and once detected -> apply BS on row
        int low = 0 , high = n-1, row = -1;
        while(low<=high){
            int guess = (low+high)/2;
            if(matrix[guess][m-1]>=target){
                row = guess;
                high = guess-1;//since we need to find the 1st row in which target occurs 
            }
            else{
                low = guess+1;
            }
        }
        if(row==-1) return false;
        //search space now low = row , high = m-1;
        int left = 0 , right = m-1;
        while(left<=right){
            int mid = (left+right)/2;
            int val = matrix[row][mid];
            if(val==target) return true;
            else if(val>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return false;
    }
    
};