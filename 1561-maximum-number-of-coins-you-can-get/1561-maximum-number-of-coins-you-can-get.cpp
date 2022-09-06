class Solution {
public:
    int maxCoins(vector<int> &piles) {
        int res = 0, n = piles.size();        
        sort(piles.begin(), piles.end());
        int k = n / 3;
        for (int i = n - 1; i > k - 1; i -= 2) {
            res += piles[i - 1];
        }
        return res;
    }
};
