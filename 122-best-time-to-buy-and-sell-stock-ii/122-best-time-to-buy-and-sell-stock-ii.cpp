class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0, n = prices.size();
        for (int i = 1; i < n; i++){
             ans += (prices[i] > prices[i-1]) ? (prices[i]-prices[i-1]) : 0;
        }
        return ans;
    }
};
