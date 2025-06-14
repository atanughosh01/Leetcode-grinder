class Solution {
private:
    int solve(int n, int k , int t, vector<vector<int>> &dp) {
        if (n == 0 && t == 0 ) return 1;
        if (n == 0) return 0;
        if (dp[n][t] != -1) return dp[n][t];
        int take = 0;
        for (int i = 1; i <= k; i++) {
            if (t >= i) {
                take  += solve(n - 1, k, t - i , dp);
                take %= 1000000007;
            }
        }
        return dp[n][t] = take;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
        return solve(n, k, target, dp);
    }
};
