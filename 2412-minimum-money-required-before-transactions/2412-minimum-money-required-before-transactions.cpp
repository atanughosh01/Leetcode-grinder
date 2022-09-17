class Solution {
public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        int mx = 0;
        for (auto &v : transactions) mx = max(mx, min(v[0], v[1]));
        long long res = mx;
        for (auto &v : transactions) res += max(0, v[0] - v[1]);
        return res;
    }
};
