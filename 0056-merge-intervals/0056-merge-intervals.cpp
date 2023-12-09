class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &vals) {
        int n = vals.size();
        sort(vals.begin(), vals.end());
        for (int i = 0; i < n - 1; i++) {
            if (vals[i][0] <= vals[i + 1][0] && vals[i][1] >= vals[i + 1][0]) {
                vals[i + 1][0] = vals[i][0];
                vals[i + 1][1] = max(vals[i + 1][1], vals[i][1]);
                vals[i] = {};
            }
        }
        sort(vals.begin(), vals.end());
        for (int j = n - 2; j >= 0; j--) {
            if (vals[j].size() != 2) {
                vals.erase(vals.begin(), vals.begin() + j + 1);
                return vals;
            }
        }
        return vals;
    }
};
