class Solution {
public:
    int findMaxK(vector<int>& a) {
        sort(a.begin(), a.end());
        int i = 0, j = a.size() - 1;
        while (i < j) {
            if (a[i] == -a[j]) {
                return a[j];
            } else if (abs(a[i]) > a[j]) {
                i++; 
            } else {
                j--; 
            }
        }
        return -1;
    }
};