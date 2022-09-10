class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        if (k > n / 2) {
            int res = 0;
            for (int i = 1; i < n; ++i) {
                res += max(prices[i] - prices[i - 1], 0);
            }
            return res;
        }
        int hold[k + 1];
        int release[k + 1];
        for (int i = 0; i <= k; i++) {
            hold[i] = INT_MIN;
            release[i] = 0;
        }
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr = prices[i];
            for (int j = k; j > 0; j--) {
                release[j] = max(release[j], hold[j] + curr);
                hold[j] = max(hold[j], release[j - 1] - curr);
            }
        }
        return release[k];
    }
};
