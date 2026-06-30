class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int low = 0;
        int ans = 0;
        int n = s.size();

        for(int high = 0; high < n; high++) {
            mp[s[high]]++;

            while(mp.size() == 3) {
                ans += n - high;

                mp[s[low]]--;
                if(mp[s[low]] == 0)
                    mp.erase(s[low]);

                low++;
            }
        }

        return ans;
    }
};