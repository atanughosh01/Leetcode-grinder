class Solution {
public:
    int largestPerimeter(vector<int> &nums) {
        int n = nums.size(), res = 0;
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || i == n - 2) break;
            if (nums[i+2] + nums[i+1] > nums[i]) {
                return nums[i+2] + nums[i+1] + nums[i];
            }
        }
        return 0;
    }
};
