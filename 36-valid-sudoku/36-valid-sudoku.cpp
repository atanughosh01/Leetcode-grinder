class Solution_1 {
public:
	bool isValidSudoku(vector<vector<char>> &board) {
		vector<unordered_set<int>> rows(9), cols(9), blocks(9);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int curr = board[i][j] - '0';
					int k = (i / 3) * 3 + j / 3;
					if (rows[i].count(curr) || cols[j].count(curr) || blocks[k].count(curr)) {
						return false;
					}
					rows[i].insert(curr);
					cols[j].insert(curr);
					blocks[k].insert(curr);
				}
			}
		}
		return true;
	}
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int rows[9][9]{0}, cols[9][9]{0}, blocks[9][9]{0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int  k = (i / 3) * 3 + j / 3;
                    if (rows[i][num] || cols[j][num] || blocks[k][num]) {
                        return false;
                    }
                    rows[i][num] = cols[j][num] = blocks[k][num] = 1;
                }
            }
        }
        return true;
    }
};
