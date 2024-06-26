class Solution {
public:
    int threeSumMulti(vector<int> &nums, int target) {
        const int mod = 1e9 + 7;
        int c[101]{0};
        long long res = 0;
        for (int &num : nums) c[num]++;
        for (int i = 0; i < 101; i++) {
            for (int j = i; j < 101; j++) {
                int k = target - i - j;
                if (k > 100 || k < 0) continue;
                if (i == j && j == k) {
                    res += c[i] * 1ll * (c[i] - 1) * 1ll * (c[i] - 2) / 6;
                } else if (i == j && j != k) {
                    res += c[i] * (c[i] - 1) / 2 * c[k];
                } else if (j < k) {
                    res += c[i] * c[j] * c[k];
                }
            }
        }
        return (res % mod);
    }
};
