class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for (char c : s) {
            // if opening - push
            if ((c == '(') || (c == '{') || (c == '[')) {
                st.push(c);
            }
            // it is a closing bracket
            else {
                if (st.empty()) {
                    return false;
                }
                if ((c == ')' && st.top() == '(') ||
                    (c == '}' && st.top() == '{') ||
                    (c == ']' && st.top() == '[')) {
                    st.pop();
                } 
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};