class Solution {
public:
    bool isPalindrome(const string &s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void solve(string s, vector<string> &diary, vector<vector<string>> &res){  
        if(s.empty()){
            res.push_back(diary);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i + 1);
            if(isPalindrome(part)){
                diary.push_back(part);
                string remaining = s.substr(i + 1); 
                solve(remaining, diary, res);
                diary.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {   
        vector<vector<string>> res;
        vector<string> path;
        solve(s, path, res);
        return res;
    }
};