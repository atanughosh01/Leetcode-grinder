class Solution {
private:
    int res = 0;
    unordered_map<int, int> mp;
    void getResult(vector<int> &nums, int target) {
        int sum = 0;
        mp.clear();
        mp[0]++;
        for (int &num : nums) {
            sum += num;
            res += mp[sum - target];
            mp[sum]++;
        }
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        vector<int> row(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++) {
            fill(row.begin(), row.end(), 0);
            for (int j = i; j < matrix.size(); j++) {
                for (int x = 0; x < matrix[0].size(); x++) {
                    row[x] += matrix[j][x];
                }
                getResult(row, target);
            }
        }
        return res;
    }
};
