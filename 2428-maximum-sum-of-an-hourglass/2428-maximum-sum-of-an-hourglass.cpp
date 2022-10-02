class Solution_1 {
public:
    int maxSum(vector<vector<int>> &G) {
        int m = G.size(), n = G[0].size();
        int res = 0;
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int sum = G[i][j] + G[i][j + 1] + G[i][j + 2] + G[i + 1][j + 1] + G[i + 2][j] + G[i + 2][j + 1] + G[i + 2][j + 2];
                res = max(res, sum);
            }
        }
        return res;
    }
};



class Solution {
public:
    int maxSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int sum = grid[i + 1][j + 1];
                for (int k = 0; k < 3; ++k) {
                    sum += grid[i][j + k] + grid[i + 2][j + k];
                }
                res = max(res, sum);
            }
        }
        return res;
    }
};
