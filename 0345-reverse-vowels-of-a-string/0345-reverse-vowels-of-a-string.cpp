class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "aeiouAEIOU";
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(vowel.find(s[l])==string::npos){
                l++;
            }
            else if(vowel.find(s[r])==string::npos){
                r--;
            }
            else{
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};