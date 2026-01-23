class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int target1 = 2 * nums[i];
            int target2 = nums[i] / 2;
            if (mpp.find(target1) != mpp.end() ||
                (nums[i] % 2 == 0 && mpp.find(target2) != mpp.end())) {
                return true;
            }
            mpp[nums[i]]++;
        }

        return false;
    }
};