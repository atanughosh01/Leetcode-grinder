class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int n = (int)(nums.size()), ans = 0;
        if (n == 1) return 0;
        if (n == 2) return abs(nums[1] - nums[0]);
        sort(nums.begin(), nums.end());
        int tar = nums[n/2];
        for (int num : nums) {
            ans += abs(tar - num);
        }
        return ans;
    }
};
