class Solution {
public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        int mx = 0;
        long long res = 0;
        for (auto &v : transactions) {
            mx = max(mx, min(v[0], v[1]));
            res += max(0, v[0] - v[1]);
        }
        res += mx;
        return res;
    }
};
