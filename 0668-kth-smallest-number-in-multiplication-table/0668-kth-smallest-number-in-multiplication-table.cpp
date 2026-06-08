class Solution {
public:
    int fun(int m,int n,int g){
        int count = 0 ;
        for(int i=1;i<=m;i++){
            count += min(n,g/i);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1 , high = m*n;
        int res = -1 ;
        while(low<=high){
            int mid = (low+high)/2;
            int val = fun(m,n,mid);
            if(val>=k){
                res = mid ;
                high = mid-1;
            }
            else{
                low = mid + 1 ;
            }
        }   
        return res;
    }
};