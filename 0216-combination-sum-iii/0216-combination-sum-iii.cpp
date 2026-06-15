class Solution {
public:
    void fun(int sum,int k ,int n , int idx,vector<int>&diary,vector<vector<int>>&res){
        if(k==0 && sum==n){
            res.push_back(diary);
            return;
        }
        if(idx>9 || k<0) return;
        fun(sum,k,n,idx+1,diary,res);
        if(sum+idx<=n){
            sum += idx;
            diary.push_back(idx);
            fun(sum,k-1,n,idx+1,diary,res);
            diary.pop_back();
            sum -= idx;
            return;
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        /*->start from 1 , keep tab of a variable named sum which is incremented every time an element is added to sum 
        ->for each i (i=1 to 9) check if i+sum<=n && k!=0, if yes include and move to next function call
        */
        vector<int>diary;
        vector<vector<int>>res;
        fun(0,k,n,1,diary,res);
        return res;
    }
};