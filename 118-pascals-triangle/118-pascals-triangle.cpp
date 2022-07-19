class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> arr;
        res.push_back({1});     
        if (numRows == 1) return res;     
        for (int i = 1; i < numRows; i++) {
            arr = {};
            for (int j = 0; j < i + 1; j++) {
                int sum = 0;
                if (j < i) sum += res[i-1][j];
                if (j >= 1) sum += res[i-1][j-1];
                arr.push_back(sum);
            }
            res.push_back(arr);
        }
        return res;
    }
};
