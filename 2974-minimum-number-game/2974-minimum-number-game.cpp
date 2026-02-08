class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(!pq.empty()){
            int alice = pq.top();
            pq.pop();
            int bob = pq.top();
            pq.pop();
            res.push_back(bob);
            res.push_back(alice);
        }
        return res;
    }
};