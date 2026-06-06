class Solution {
public:
    bool possible(vector<int>& v, int days,int m, int k){
        int count = 0, numOfB = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= days) {
                count++;
                
            } else {
                numOfB += count/k;
                count = 0;
            }
        }
        numOfB += count/k;
        return numOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL * m * k > n) return -1; 
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int low = mini, high = maxi, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};