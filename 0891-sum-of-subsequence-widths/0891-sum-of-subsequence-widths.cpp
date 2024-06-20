class Solution {
public:
    int sumSubseqWidths(vector<int> &nums) {
        const int mod = 1e9 + 7;
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        vector<long> exp(n, 0);
        exp[0] = 1;
        for (int i = 1; i < n; i++) {
            exp[i] = exp[i - 1] * 2 % mod;
        }
        for (int i = 0; i < n; i++) {
            ans = (ans + exp[i] * (nums[i] - nums[n - i - 1])) % mod;
        }    
        return ans;
    }
};
