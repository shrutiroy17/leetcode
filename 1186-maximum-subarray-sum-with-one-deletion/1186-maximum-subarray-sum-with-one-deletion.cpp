class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0];
        int oneDel = INT_MIN;
        int res = arr[0];
        for(int i=1;i<n;i++){
            int prevNoDel = noDel;
            noDel = max(noDel+arr[i],arr[i]);
            if(oneDel==INT_MIN){
                oneDel = prevNoDel;
            }
            else{
                oneDel = max(oneDel+arr[i],prevNoDel);
            }
            res = max(res,max(noDel,oneDel));
        }
        return res;
    }
};