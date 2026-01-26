class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int guess = (high+low)/2;
            if(arr[guess]>arr[guess+1]){
                ans = guess;
                high = guess-1;
            }
            else{
                low = guess+1;
            }
        }
        return ans;
    }
};