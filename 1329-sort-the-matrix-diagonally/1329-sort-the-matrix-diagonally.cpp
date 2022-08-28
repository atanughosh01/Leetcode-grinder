class Solution_1 {
private:
    void sort(int i, int j, int m, int n, vector<vector<int>> &mat) {
        for (; i < m && j < n; i++, j++) {
            int a = i, b = j;
            while (a < m && b < n) {
                if (mat[a][b] < mat[i][j]) {
                    swap(mat[a][b], mat[i][j]);
                }
                a++;
                b++;
            }
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < n; i++) sort(0, i, m, n, mat);
        for (int i = 1; i < m; i++) sort(i, 0, m, n, mat);
        return mat;
    }
};



class Solution_2 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        unordered_map<int, vector<int>> mp;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }
        for (int x = -(n - 1); x < m; x++) {
            sort(mp[x].begin(), mp[x].end());
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        return mat;
    }
};



class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push(mat[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mp[i - j].top();
                mp[i - j].pop();
            }
        }
        return mat;
    }
};
