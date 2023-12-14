class Solution {
public:
	vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
		int m = grid.size(), n = grid[0].size();
		vector<int> zeroRows(m, 0), zeroCols(n, 0);
		vector<int> oneRows(m, 0), oneCols(n, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					zeroRows[i]++;
					zeroCols[j]++;
				} else {
					oneRows[i]++;
					oneCols[j]++;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				grid[i][j] = (oneRows[i] + oneCols[j]) - (zeroRows[i] + zeroCols[j]);
			}
		}
		return grid;
	}
};
