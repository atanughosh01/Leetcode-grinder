class Solution {
private:
    void sort(int i, int j, int m, int n, vector<vector<int>>& mat) {
        for (; i < m && j < n; i++, j++) {
            int a = i, b = j;
            while (a < m && b < n) {
                if (mat[a][b] < mat[i][j])
                    swap(mat[a][b], mat[i][j]);
                a++;
                b++;
            }
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < n; i++) sort(0, i, m, n, mat);
        for (int i = 1; i < m; i++) sort(i, 0, m, n, mat);
        return mat;
    }
};
