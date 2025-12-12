class Solution {
public:
    int find(vector<int>& a) {
        int maxc = -1;
        for (int i = 0; i < 256; i++)
            maxc = max(maxc, a[i]);
        return maxc;
    }

    int characterReplacement(string s, int k) {
        int low = 0;
        int high = 0;
        int ans = 0;
        int n = s.size();
        vector<int> f(256, 0);
        while (high < n) {
            f[s[high]]++;
            int maxCount = find(f);
            int len = high - low + 1;
            int diff = len - maxCount;
            while(diff>k){
                f[s[low]]--;
                low++;
                maxCount = find(f);
                len = high-low+1;
                diff = len - maxCount;
            }
            len = high-low+1;
            ans = max(ans,len);
            high++;
        }
        return ans;
    }
};