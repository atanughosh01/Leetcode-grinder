class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        long long dp[501] = {startFuel};
        for (int i = 0; i < stations.size(); i++) {
            for (int t = i; t >= 0 && dp[t] >= stations[i][0]; t--) {
                dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
            }
        }
        for (int t = 0; t <= stations.size(); ++t) {
            if (dp[t] >= target) {
                return t;
            }
        }
        return -1;
    }
};
