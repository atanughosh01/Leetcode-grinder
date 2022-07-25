class Solution {
public:
    int countNegatives(vector<vector<int>> &grid) {
        int count = 0, n = grid[0].size();
        for (vector<int> &arr : grid) {
            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] < 0)  count++;
                else break;
            }
        }
        return count;
    }
};
