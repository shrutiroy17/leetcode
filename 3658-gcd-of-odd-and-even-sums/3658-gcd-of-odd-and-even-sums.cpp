class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0 , sumEven = 0;
        int odd = 1 , even = 2;
        while(n--){
            sumOdd += odd;
            odd += 2;
            sumEven += even;
            even += 2;
        }
        for(int i=min(sumOdd,sumEven);i>=1;i--){
            if(sumOdd%i==0 && sumEven%i==0){
                return i;
            }
        }
        return -1;
    }
};