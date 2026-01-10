class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int low = 0;
        int high = 0;
        unordered_map<char,int>mpp;
        while(high<n){
            mpp[s[high]]++;
            while(high-low+1>3){
                mpp[s[low]]--;
                if(mpp[s[low]]==0){
                    mpp.erase(s[low]);
                }
                low++;
            }
            int len = high-low+1;
            if(mpp.size()==3 && len==3){
                count++;
            }
            high++; 
        }
        return count;
    }
};