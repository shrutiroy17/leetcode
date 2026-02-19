class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        vector<int> freq(37, 0);  
        // Max digit sum for n <= 10^4 is 36 (9999 → 9+9+9+9)

        for (int i = 1; i <= n; i++) {
            int sum = digitSum(i);
            freq[sum]++;
        }

        int maxSize = 0;
        for (int count : freq) {
            maxSize = max(maxSize, count);
        }

        int result = 0;
        for (int count : freq) {
            if (count == maxSize)
                result++;
        }

        return result;
    }
};
