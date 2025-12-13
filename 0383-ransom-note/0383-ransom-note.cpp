class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp;
        for (char cm : magazine) {
            mpp[cm]++;
        }
        int needed = ransomNote.size();
        for (char cr : ransomNote) {
            if (mpp.find(cr) != mpp.end()) {
                needed--;
                mpp[cr]--;
                if (mpp[cr] == 0) {
                    mpp.erase(cr);
                }
            }
        }
        if (needed == 0) {
            return true;
        }
        return false;
    }
};