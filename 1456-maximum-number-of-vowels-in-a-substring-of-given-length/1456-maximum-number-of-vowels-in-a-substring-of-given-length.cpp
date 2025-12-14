class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int low = 0;
        int high = k-1;
        int res = 0;
        int count = 0;
        for(int i = 0;i<=high;i++){
            if(isVowel(s[i])){
                count++;
            }   
        }
        res = count;
        int n = s.size();
        while(high<n){
            res = max(res,count);
            if(isVowel(s[low])){
                count--;
            }
            low++;
            high++;
            if(high==n){
                break;
            }
            if(isVowel(s[high])) count++;
        }
        return res;
    }
};