class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<int> rows(n, 0), cols(n, 0);
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        
        int sum = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                sum += max((min(rows[i], cols[j]) - grid[i][j]), 0);
            }
        }
        
        return sum;
    }
};
