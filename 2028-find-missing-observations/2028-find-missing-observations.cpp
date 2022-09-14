class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int curSum = accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = mean * (n + m) - curSum;
        if (missingSum < n || missingSum > 6 * n) return {};
        int part = missingSum / n, rem = missingSum % n;
        vector<int> ans(n, part);
        for (int i = 0; i < rem; ++i) ans[i]++;
        return ans;
    }
};
