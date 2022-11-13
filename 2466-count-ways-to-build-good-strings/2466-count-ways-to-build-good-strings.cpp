class Solution {
public:
	int countGoodStrings(int low, int high, int zero, int one) {
		const long long MOD  = 1e9 + 7, N = 2e5 + 3, M = 1e5 + 1;
		long long sum = 0;
		vector<long long> res(N);
		res[0] = 1;
		for (int i = 0; i < M; i++) {
			res[i + zero] = (res[i + zero] % MOD + res[i] % MOD) % MOD;
			res[i + one] = (res[i + one] % MOD + res[i] % MOD) % MOD;
            if (i >= low && i <= high) {
			    sum = (sum % MOD + res[i] % MOD) % MOD;
            }
		}
		return sum;
	}
};
