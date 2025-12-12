class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n)
            return "";
        int hash[256] = {0};
        for (char c : t)
            hash[c]++;
        int l = 0, count = m;
        int minLen = INT_MAX, startInd = 0;
        for (int r = 0; r < n; r++) {
            if (hash[s[r]] > 0)
                count--;
            hash[s[r]]--;
            while (count == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startInd = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    count++;
                l++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(startInd, minLen);
    }
};