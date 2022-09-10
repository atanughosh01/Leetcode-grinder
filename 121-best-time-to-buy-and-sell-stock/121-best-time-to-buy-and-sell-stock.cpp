// Bruteforce | O(n*n) Time | O(1) Space | n = prices.length
class Solution_1 {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size(), res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int profit = prices[j] - prices[i];
                res = max(res, profit);
            }
        }
        return res;
    }
};



// Optimal | O(n) Time | O(1) Space | n = prices.length
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0, buyPrice = INT_MAX;
        for (int price : prices) {
            buyPrice = min(buyPrice, price);
            profit = max(profit, price - buyPrice);
        }
        return profit;
    }
};
