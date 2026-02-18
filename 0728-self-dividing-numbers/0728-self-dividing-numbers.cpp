class Solution {
public:
    bool fun(int n){
        int temp = n;
        while(n > 0){
            int digit = n % 10;
            if(digit == 0 || temp % digit != 0)
                return false;
            n = n / 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;   
        for(int i = left; i <= right; i++){
            if(fun(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};
