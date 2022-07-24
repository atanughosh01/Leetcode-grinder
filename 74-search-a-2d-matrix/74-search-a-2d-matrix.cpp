// TC : O(m*log(n))
class Solution_1 {
public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = l + (r - l)/2;
                if (target == mat[i][mid]) return true;
                if (target < mat[i][mid]) r = mid - 1;
                if (target > mat[i][mid]) l = mid + 1;
            }
        }
        return false;
    }
};



// TC : O(log(m*n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int l = 0, r = m*n - 1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (target == mat[mid/n][mid%n]) return true;
            if (target < mat[mid/n][mid%n]) r = mid - 1;
            if (target > mat[mid/n][mid%n]) l = mid + 1;
        }
        return false;
    }
};
