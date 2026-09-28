class Solution {
public:
    int maxDepth(string s) {
        int count = 0 , res = 0 ;
        stack<char>st;
        for(char c:s){
            if(c==')' && st.top()=='('){
                st.pop();
                count--;
            }
            else if(c=='(') {
                st.push(c);
                count++;
            }
            res = max(res,count);
        }
        return res ;
    }
};