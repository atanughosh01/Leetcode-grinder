class Solution {
public:
	int cherryPickup(vector<vector<int>> &grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> prevDp(n, vector<int>(n));
		for (int row = 0; row < m; row++) {
			vector<vector<int>> currentDp(n, vector<int>(n));
			for (int c1 = 0; c1 < min(n, row + 1); c1++) {
				for (int c2 = max(0, n - 1 - row); c2 < n; c2++) {
					int prevMax = 0;
					for (int offset1 = max(0, c1 - 1); offset1 <= min(n - 1, c1 + 1); offset1++) {
						for (int offset2 = max(0, c2 - 1); offset2 <= min(n - 1, c2 + 1); offset2++) {
							prevMax = max(prevMax, prevDp[offset1][offset2]);
						}
					}
					if (c1 == c2) {
						currentDp[c1][c2] = prevMax + grid[row][c1];
					} else {
						currentDp[c1][c2] = prevMax + grid[row][c1] + grid[row][c2];
					}
				}
			}
			prevDp = currentDp;
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res = max(res, prevDp[i][j]);
			}
		}
		return res;
	}
};
