class Solution {
public:
    bool possible(vector<int>& candies, long long k, int mid) {
    long long children = 0;
    for(int pile : candies) {
        children += pile / mid;
    }
    return children >= k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1 , high = *max_element(candies.begin(),candies.end()) , res = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(candies,k,mid)){
                res = mid;
                low = mid+1;
            }
            else 
            high = mid-1;
        }
        return res;
    }
};