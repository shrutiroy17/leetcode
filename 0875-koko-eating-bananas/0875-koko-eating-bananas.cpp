class Solution {
public:
    long long findHours(vector<int>& a, int speed) {
        long long hr = 0;
        for (int x : a) {
            hr += (x + speed - 1) / speed;
        }
        return hr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = -1;
        while(low<=high){
            int guess = low + (high - low)/2;
            long long hours = findHours(piles,guess);
            if(hours>h){
                low = guess+1;
            }
            else{
                res = guess;
                high = guess-1;
            }
        }
        return res;
    }
};