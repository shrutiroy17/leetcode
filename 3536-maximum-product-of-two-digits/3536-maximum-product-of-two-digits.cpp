class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        sort(num.begin(),num.end());
        int temp = n;
        int digit = 0;
        while(temp>0){
            digit++;
            temp /= 10;
        }
        int s = num.size();
        int ans = 1 ;
        if(digit==2) {
            ans = (num[1] - '0') * (num[0] - '0'); 
        }
        else{
            ans = (num[s-1] - '0') * (num[s-2] - '0');
        }
        return ans;
    }
};