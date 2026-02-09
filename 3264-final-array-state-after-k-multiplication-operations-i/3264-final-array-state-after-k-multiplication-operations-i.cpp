class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second>b.second;
        }
    };
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto p = pq.top();
            pq.pop();
            int val = p.first;
            int ind = p.second;
            pq.push({val*multiplier,ind});
            nums[ind] = val*multiplier;
        }
        return nums;
    }
};