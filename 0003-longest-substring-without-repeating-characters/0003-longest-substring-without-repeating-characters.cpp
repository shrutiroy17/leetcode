class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0, ans = 0;
        unordered_map<char, int> mpp;
        for (int high = 0; high < n; high++) {
            mpp[s[high]]++;
            int k = high - low + 1;
            while (mpp.size() < k) {
                mpp[s[low]]--;
                if (mpp[s[low]] == 0)
                    mpp.erase(s[low]);
                low++;
                k = high - low + 1;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};