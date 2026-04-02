class Solution {
public:
    void fun(vector<int>& a,int n,int idx,int sum,vector<int>&diary,vector<vector<int>>&res, int t){
        if(sum==t){
            res.push_back(diary);
            return;
        }
        if (sum > t || idx == n)
            return;
        //exclude-skip all duplicates
        int next = idx+1;
        while(next<n && a[next]==a[idx]) next++;
        fun(a,n,next,sum,diary,res,t);
        if(sum+a[idx]<=t){
            sum += a[idx];
            diary.push_back(a[idx]);
            fun(a,n,idx+1,sum,diary,res,t);
            sum -= a[idx];
            diary.pop_back();
            return;
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        int n = candidates.size();
        int idx = 0;
        int sum = 0;
        vector<int>diary;
        fun(candidates,n,idx,sum,diary,res,target);
        return res;
    }
};