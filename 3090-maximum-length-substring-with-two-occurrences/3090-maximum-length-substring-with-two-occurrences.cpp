class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size() ;
        int low = 0 , high = 0 ;
        int res = -1 ;
        unordered_map<char,int>mpp;
        while(high<n){
            mpp[s[high]]++ ;
            while(mpp[s[high]]>2){
                mpp[s[low]]-- ;
                if(mpp[s[low]]==0) mpp.erase(s[low]) ;
                low++ ;
            }
            res = max(res,high-low+1) ;
            high++ ;
        }
        return res ;
    }
};