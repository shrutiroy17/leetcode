class Solution {
public:
    int maximumLengthSubstring(string s) {
      int n = s.size();
      int low = 0;
      int maxLen = 0;
      unordered_map<char,int>freq;
      for(int high=0;high<n;high++){
        freq[s[high]]++;
        while(freq[s[high]]>2){
            freq[s[low]]--;
            if(freq[s[low]]==0){
                freq.erase(s[low]);
            }
            low++;
        }
        maxLen = max(maxLen,high-low+1);
      }  
      return maxLen;
    }
};