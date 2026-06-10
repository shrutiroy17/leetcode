class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        string curr;
        stringstream ss (path);
        while(getline(ss,curr,'/')){
            if(curr.empty() || curr=="."){
                continue;
            }
            if(curr==".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }
            else
            st.push_back(curr);
        }
        string res = "";
        for(string dir:st){
            res += "/"+dir;
        }
        return res.empty() ? "/" : res;
    }
};