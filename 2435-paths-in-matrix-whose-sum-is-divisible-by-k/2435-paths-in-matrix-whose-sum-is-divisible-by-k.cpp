class Solution {
private:
    const int mod = (int)1e9 + 7;
    int solve(int i, int j, vector<vector<int>> &grid, int k, int pathSum, vector<vector<vector<int>>> &dp) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        if (dp[i][j][pathSum % k] != -1) return dp[i][j][pathSum % k];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            pathSum += grid[i][j];
            return (pathSum % k == 0);
        }
        int down = solve(i + 1, j, grid, k, pathSum + grid[i][j], dp) % mod;
        int right = solve(i, j + 1, grid, k, pathSum + grid[i][j], dp) % mod;
        return dp[i][j][pathSum % k] = ((down + right) % mod);

    }
public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, grid, k, 0, dp) % mod;
    }
};
