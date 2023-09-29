class Solution {
public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        int mx = 0;
        long long res = 0;
        for (auto &t : transactions) {
            mx = max(mx, min(t[0], t[1]));
            res += max(0, t[0] - t[1]);
        }
        res += mx;
        return res;
    }
};
