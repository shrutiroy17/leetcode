class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        double n = a.size();
        if(n==1){
            return a[0];
        }
        double low = 0;
        double high = k-1;
        double sum = 0;
        double avg = 0;
        double res = INT_MIN;
        for(double i=0;i<=high;i++){
            sum+=a[i];
        }
        avg = sum/k;
        res = max(res,avg);
        while(high<n){
            sum-=a[low];
            low++;
            high++;
            if(high==n)
            break;
            sum+=a[high];
            avg = sum/k;
            res = max(res,avg);
        }
        return res;
    }
};