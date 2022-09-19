class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        int total = m * n;
        if (total != original.size()) return {};
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < total; i++) {
            res[i / n][i % n] = original[i];
        }
        return res;
    }
};
