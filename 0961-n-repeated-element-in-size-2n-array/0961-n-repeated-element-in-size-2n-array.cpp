class Solution_1 {
  public:
	int repeatedNTimes(vector<int> &A) {
		sort(A.begin(), A.end());
		for (size_t i = 0; i < A.size() - 1; i++) {
			if (A[i] == A[i + 1]) {
                return A[i];
            }
		}
		return 0;
	}
};


class Solution {
  public:
	int repeatedNTimes(vector<int> &A) {
		unordered_map<int, int> map;
		for (int i = 0; i < A.size(); i++) {
			if (map[A[i]] > 0) {
				return A[i];
            }
			map[A[i]]++;
		}
		return 0;
	}
};
