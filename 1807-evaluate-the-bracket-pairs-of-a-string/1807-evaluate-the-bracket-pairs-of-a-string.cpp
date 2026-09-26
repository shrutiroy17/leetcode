class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto &x:knowledge){
            mpp[x[0]] = x[1] ;
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                i++;
                string key = "";
                while(s[i]!=')'){
                    key += s[i] ;
                    i++;
                }
                if(mpp.find(key)!=mpp.end()){
                    ans += mpp[key];
                }
                else ans += '?';
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};