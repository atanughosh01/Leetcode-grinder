class Solution {
private:
	bool dfs(vector<vector<char>> &board, const string &word, int r, int c, int idx) {
		if (idx == word.size()) return true;
		if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[idx]) {
            return false;
        }
		board[r][c] = '*';
		bool res =  dfs(board, word, r + 1, c, idx + 1) ||
		            dfs(board, word, r - 1, c, idx + 1) ||
		            dfs(board, word, r, c - 1, idx + 1) ||
		            dfs(board, word, r, c + 1, idx + 1);
		board[r][c] = word[idx];
		return res;
	}
public:
	bool exist(vector<vector<char>> &board, string &word) {
		int rows = board.size(), cols = board[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (dfs(board, word, i, j, 0)) {
					return true;
				}
			}
		}
		return false;
	}
};
