class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int count0 = 0;
        int count1 = 0;
        int ans = 0;
        int low = 0;
        for(int high=0;high<n;high++){
            if(s[high]=='0') count0++;
            else count1++;
            while(count0>k && count1>k){
                if(s[low]=='0') count0--;
                else count1--;
                low++;
            }
            ans += high-low+1;
        }
        return ans;
    }
};