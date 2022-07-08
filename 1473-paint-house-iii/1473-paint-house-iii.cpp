class Solution {
private:
    int dp[105][105][105];
    int num = 0;
    int helper(vector<int> &houses, vector<vector<int>> &cost, int i, int last, int tar) {
        if (i >= houses.size()) {
            if (tar == 0) return 0;
            return 1e9;
        }
        if (tar < 0) return 1e9;
        if (dp[i][last][tar] != -1) return dp[i][last][tar];
        if (houses[i] == 0) {
            int min_i = 1e9;
            for (int col = 1; col <= num; col++) {
                int targ = tar;
                if (col != last) targ--;
                min_i = min(min_i, cost[i][col - 1] + helper(houses, cost, i + 1, col, targ));
            }
            return dp[i][last][tar] = min_i;
        } else {
            int targ = tar;
            if (houses[i] != last) {
                targ--;
            }
            return dp[i][last][tar] = helper(houses, cost, i + 1, houses[i], targ);
        }
    }
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        num = n;
        int ans = helper(houses, cost, 0, 0, target);
        return ans == 1e9 ? -1 : ans;
    }
};
