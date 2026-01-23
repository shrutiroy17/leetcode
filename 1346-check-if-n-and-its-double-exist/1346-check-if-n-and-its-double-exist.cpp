class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto x : nums){
            if(seen.count(2*x) || (x%2==0 && seen.count(x/2)))
            return true;
            seen.insert(x);
        }
        return false;
    }
};