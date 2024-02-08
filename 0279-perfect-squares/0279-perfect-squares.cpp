class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int count = 1;
        while (count * count <= n) {
            int sqr = count * count;
            for (int i = sqr; i < n + 1; i++) {
                dp[i] = min(dp[i - sqr] + 1, dp[i]);
            }
            count++;
        }
        return dp[n];
    }
};
