class Solution {
public:
    unordered_map<char, string> f = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void fun(string& digits, int n, int idx, string& diary,
        vector<string>& res) {
        if (idx == n) {
            res.push_back(diary);
            return;
        }
        string choices = f[digits[idx]];
        for (int j = 0; j < choices.size(); j++) {
            diary.push_back(choices[j]);
            fun(digits, n, idx + 1, diary, res);
            diary.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        int n = digits.size();
        vector<string> res;
        string diary = "";
        int idx = 0;
        fun(digits, n, idx, diary, res);
        return res;
    }
};