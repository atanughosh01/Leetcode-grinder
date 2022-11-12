class Solution {
public:
	int countGoodStrings(int low, int high, int zero, int one) {
		const long long mod  = 1e9 + 7, N = 2e5 + 3, M = 1e5 + 1;
		long long sums = 0;
		vector<long long> res(N);
		res[0] = 1;
		for (int i = 0; i < M; i++) {
			res[i + zero] %= mod;
			res[i + zero] += res[i];
			res[i + one] %= mod;
			res[i + one] += res[i];
		}
		for (int i = low; i <= high; i++) {
			sums = (sums % mod + res[i] % mod) % mod;
		}
		return sums;
	}
};
