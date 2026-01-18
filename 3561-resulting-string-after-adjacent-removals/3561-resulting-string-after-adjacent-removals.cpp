class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(char c:s){
            if (!st.empty() &&
               ( abs(st.top() - c) == 1 ||
                 (st.top() == 'a' && c == 'z') ||
                 (st.top() == 'z' && c == 'a') )) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};