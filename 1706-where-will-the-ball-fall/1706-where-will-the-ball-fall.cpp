class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, 0);
         for (int col = 0; col < n; col++) {
            int currentCol = col;
            for (int row = 0; row < m; row++) {
                int nextColumn = currentCol + grid[row][currentCol];
                if (nextColumn < 0 || nextColumn > n - 1 ||
                    grid[row][currentCol] != grid[row][nextColumn]) {
                    res[col] = -1;
                    break;
                }
                res[col] = nextColumn;
                currentCol = nextColumn;
            }
        }
        return res;
    }
};
