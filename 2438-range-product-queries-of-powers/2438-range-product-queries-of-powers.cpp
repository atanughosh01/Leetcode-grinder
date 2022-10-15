class Solution_1 {
public:
	vector<int> productQueries(int n, vector<vector<int>> &queries) {
		const int mod = 1e9 + 7;
		int sz = queries.size(), idx = 0;
		vector<int> temp, powSum, res(sz);
		while (n > 0) {
			temp.push_back(n % 2);
			n /= 2;
		}
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 1) {
				int t = pow(2, i);
				powSum.push_back(t);
			}
		}
		for (auto &row : queries) {
			long long sum = 1;
			for (int i = row[0]; i <= row[1]; i++) {
				sum = (sum * powSum[i] % mod);
			}
			res[idx++] = sum % mod;
		}
		return res;
	}
};



class Solution {
public:
	vector<int> productQueries(int n, vector<vector<int>> &queries) {
		const int mod = 1e9 + 7;
		vector<long long> powers;
		vector<int> res;
		long long curr = 1;
		while (n) {
			if (n & 1) {
				powers.push_back(curr);
			}
			n /= 2;
            curr *= 2;
		}
		for (auto &x : queries) {
			curr = 1;
			for (auto i = x[0]; i <= x[1]; i++) {
				(curr *= powers[i]) %= mod;
			}
			res.push_back(curr);
		}
		return res;
	}
};
