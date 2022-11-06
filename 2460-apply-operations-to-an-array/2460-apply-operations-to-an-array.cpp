class Solution {
public:
    vector<int> applyOperations(vector<int> &nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        for (int &x : nums) {
            if (x != 0) {
                res.push_back(x);
            }
        }
        for (int &x : nums) {
            if (x == 0) {
                res.push_back(x);
            }
        }
        return res;
    }
};
