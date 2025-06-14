class Solution {
private: 
    vector<vector<int>> dp;
    int solve(vector<int> &nums, vector<int> &muls, int start, int end, int idx) {
        if (idx == muls.size()) return 0;
        if (dp[start][idx] != INT_MAX) return dp[start][idx];
        int pickLeft = (muls[idx] * nums[start]) + solve(nums, muls, start + 1, end, idx + 1);
        int pickRight = (muls[idx] * nums[end]) + solve(nums, muls, start, end - 1, idx + 1);
        return dp[start][idx] = max(pickLeft, pickRight);
    }
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        int m = multipliers.size(), n = nums.size();
        dp = vector<vector<int>>(m + 1, vector<int>(m + 1, INT_MAX));
        return solve(nums, multipliers, 0, n - 1, 0);
    }
};
