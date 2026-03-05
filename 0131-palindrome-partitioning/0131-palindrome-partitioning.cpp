class Solution {
public:
    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string &s, int start, vector<string> &path, vector<vector<string>> &res){  
        if(start == s.length()){
            res.push_back(path);
            return;
        }
        for(int end = start; end < s.length(); end++){
            
            if(isPalindrome(s, start, end)){     
                path.push_back(s.substr(start, end - start + 1)); 
                solve(s, end + 1, path, res);
                path.pop_back(); // backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {   
        vector<vector<string>> res;
        vector<string> path;
        solve(s, 0, path, res);
        return res;
    }
};