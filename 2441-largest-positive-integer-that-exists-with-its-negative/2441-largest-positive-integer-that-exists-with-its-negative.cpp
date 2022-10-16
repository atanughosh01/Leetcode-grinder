class Solution {
public:
    int findMaxK(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < 0) return -1;
            if (binary_search(nums.begin(), nums.end(), -nums[i])) {
                return nums[i];
            }
        }
        return -1;
    }
};
