class Solution {
public:
    vector<int> buildArray(vector<int> &nums) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(nums[num]);
        }
        return res;
    }
};
