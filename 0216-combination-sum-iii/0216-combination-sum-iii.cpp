class Solution {
public:
    void fun(int start,int k ,int n , vector<int>&diary,vector<vector<int>>&res){
        if(k==0 && n==0){
            res.push_back(diary);
            return;
        }
        if (k == 0 || n < 0) return;
        for(int i=start;i<=9;i++){
            diary.push_back(i);
            fun(i+1,k-1,n-i,diary,res);
            diary.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        /*->start from 1 , keep tab of a variable named sum which is incremented every time an element is added to sum 
        ->for each i (i=1 to 9) check if i+sum<=n && k!=0, if yes include and move to next function call
        */
        vector<int>diary;
        vector<vector<int>>res;
        fun(1,k,n,diary,res);
        return res;
    }
};