class Solution_1 {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = (int)(cost.size());
        vector<int> dp(n + 1);        
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = dp[i - 1] + cost[i - 1];
            int jumpTwoStep = dp[i - 2] + cost[i - 2];
            dp[i] = min(jumpOneStep, jumpTwoStep);
        }
        return dp[n];
    }
};



class Solution_2 {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = (int)(cost.size());
        vector<int> dp(3);
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = dp[(i-1) % 3] + cost[i - 1];
            int jumpTwoStep = dp[(i-2) % 3] + cost[i - 2];
            dp[i % 3] = min(jumpOneStep, jumpTwoStep);
        }
        return dp[n % 3];
    }
};



class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = (int)(cost.size());
        int dp = 0, dp1 = 0, dp2 = 0;
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = dp1 + cost[i - 1];
            int jumpTwoStep = dp2 + cost[i - 2];
            dp = min(jumpOneStep, jumpTwoStep);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};
