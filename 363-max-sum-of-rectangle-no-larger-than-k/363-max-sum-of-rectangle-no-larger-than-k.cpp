class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int res = INT_MIN;
        for (int l = 0; l < col; ++l) {
            vector<int> sums(row, 0);
            for (int r = l; r < col; ++r) {
                for (int i = 0; i < row; ++i) {
                    sums[i] += matrix[i][r];
                } 
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : sums) {
                    curSum += sum;
                    auto it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end()) {
                        curMax = max(curMax, curSum - *it);
                    }
                    accuSet.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};
