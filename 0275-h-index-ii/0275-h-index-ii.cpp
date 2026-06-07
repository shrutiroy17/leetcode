class Solution {
public:
    bool isPossible(vector<int>&c, int guess){
        int count = 0 ;
        for(int x:c){
            if(x>=guess) count++;
        }
        return count>=guess;
    }
    int hIndex(vector<int>& citations) {
        int low = 0 ;
        int high = *max_element(citations.begin(),citations.end());
        int res = 0 ;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(citations,mid)){
                res = mid ;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }
};