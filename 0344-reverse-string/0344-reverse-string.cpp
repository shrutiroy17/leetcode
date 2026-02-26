class Solution {
public:
    void revHelper(vector<char>& s,int l,int r){
        if(l>=r) return;
        swap(s[l],s[r]);
        revHelper(s,l+1,r-1);
    }
    void reverseString(vector<char>& s) {
        revHelper(s,0,s.size()-1);
    }
};