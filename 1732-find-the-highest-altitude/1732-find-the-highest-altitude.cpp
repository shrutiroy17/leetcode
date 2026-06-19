class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int dist = 0 ;
        int res = 0 ;
        for(int i=0;i<n;i++){
            dist = dist+gain[i];
            res = max(res,dist);
        }
        return res;
    }
};