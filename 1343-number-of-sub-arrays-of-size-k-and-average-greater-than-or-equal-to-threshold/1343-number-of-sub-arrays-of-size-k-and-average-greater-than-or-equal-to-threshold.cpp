class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int low = 0;
        int high = k-1;
        int sum = 0;
        int avg = 0;
        int count = 0;
        for(int i=0;i<=high;i++){
            sum+=arr[i];
        }
        avg = sum/k;
        if(avg>=threshold) count++;
        while(high<n){
            sum -= arr[low];
            low++;
            high++;
            if(high==n) break;
            sum += arr[high];
            avg = sum/k;
            if(avg>=threshold) count++;
        }
        return count;
    }
};