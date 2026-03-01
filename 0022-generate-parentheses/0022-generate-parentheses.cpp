class Solution {
public:
    void helper(int open,int close,int n,string&tmp,vector<string>&res){
        if(open==n && close==n){
            res.push_back(tmp);
            return;
        }
        if(open<n){
            tmp.push_back('(');
            helper(open+1,close,n,tmp,res);
            tmp.pop_back();
        }
        if(close<open){
            tmp.push_back(')');
            helper(open,close+1,n,tmp,res);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        helper(0,0,n,temp,result);
        return result;
    }
};