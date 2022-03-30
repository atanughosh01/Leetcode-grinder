/*
    // TC : O(n*log(m))
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& mat, int target) {
            int n = mat.size(), m = mat[0].size();
            for (int i=0; i<n; i++) {
                int l = 0, r = m-1;
                while (l <= r) {
                    int mid = l + (r-l)/2;
                    if (target == mat[i][mid]) return true;
                    if (target < mat[i][mid]) r = mid - 1;
                    if (target > mat[i][mid]) l = mid + 1;
                }
            }
            return false;
        }
    };
*/


// TC : O(log(m*n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = m*n - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (target == mat[mid/m][mid%m]) return true;
            if (target < mat[mid/m][mid%m]) r = mid - 1;
            if (target > mat[mid/m][mid%m]) l = mid + 1;
        }
        return false;
    }
};
