class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
		int n = grid.size(), ans = 0;
		vector<int> rows(n, 0), cols(n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				rows[i] = max(rows[i], grid[i][j]);
				cols[j] = max(cols[j], grid[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans += max((min(rows[i], cols[j]) - grid[i][j]), 0);
			}
		}
		return ans;
	}
};
