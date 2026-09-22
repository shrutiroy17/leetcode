class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = INT_MIN ;
        int n = heights.size() ;
        int left = 0 , right = n - 1 ;
        while(left<right){
            int mul = right - left ;
            int ht = min(heights[left],heights[right]) ;
            int area = mul * ht ;
            res = max(res,area) ;
            heights[left]<heights[right] ? left++ : right-- ;
        }
        return res ;
    }
};