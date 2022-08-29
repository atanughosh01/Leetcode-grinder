class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxProf = 0, l = 0;
        int n = prices.size();
        for (int r = 0; r < n; r++) {
            int diff = prices[r] - prices[l];
            if (diff < 0) l++, r--;
            else maxProf = max(diff, maxProf);
        }
        return maxProf;
    }
};
