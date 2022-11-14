class Solution {
protected:
	int dfs(vector<vector<int>> &stones, int idx, vector<bool> &visited, int &n) {
		visited[idx] = true;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])) {
				res += dfs(stones, i, visited, n) + 1;
			}
		}
		return res;
	}
public:
	int removeStones(vector<vector<int>> &stones) {
		int n = stones.size(), res = 0;
		vector<bool> visited(n, 0);
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				res += dfs(stones, i, visited, n);
			}
		}
		return res;
	}
};
