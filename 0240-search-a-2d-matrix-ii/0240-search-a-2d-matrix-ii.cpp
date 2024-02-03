// TC : O(m*log(n)), SC: O(1)
class Solution_1 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int l = 0, r  = n - 1;
            while (l <= r) {
                int mid = l + (r - l)/2;
                if (target == matrix[i][mid]) return true;
                else if (target > matrix[i][mid]) l = mid + 1;
                else if (target < matrix[i][mid]) r = mid - 1;
            }
        }
        return false;
    }
};


// TC : O(n*log(m)), SC: O(1)
class Solution_2 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < n; i++) {
            int l = 0, r  = m - 1;
            while (l <= r) {
                int mid = l + (r - l)/2;
                if (target == matrix[mid][i]) return true;
                else if (target > matrix[mid][i]) l = mid + 1;
                else if (target < matrix[mid][i]) r = mid - 1;
            }
        }
        return false;
    }
};


// TC : O(log(m+n)), SC: O(1)
class Solution_3 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while (col >= 0 && row <= matrix.size() - 1) {
            if (target == matrix[row][col]) return true;
            else if (target < matrix[row][col]) col--;
            else if (target > matrix[row][col]) row++;
        }
        return false;
    }
};


// TC : O(log(m+n)), SC: O(1) but slightly more optimized
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while (col >= 0 && row <= matrix.size() - 1) {
            if (target < matrix[row][col]) col--;
            else if (target > matrix[row][col]) row++;
            else return true;
        }
        return false;
    }
};
