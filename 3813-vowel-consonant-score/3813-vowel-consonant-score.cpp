class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int vowelConsonantScore(string s) {
        int vow = 0, cons = 0;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                if (isVowel(c))
                    vow++;
                else
                    cons++;
            }
        }
        return cons > 0 ? vow / cons : 0;
    }
};
