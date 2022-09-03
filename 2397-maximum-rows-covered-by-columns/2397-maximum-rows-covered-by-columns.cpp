class Solution {
public:
    int maximumRows(vector<vector<int>> &mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        int perm = pow(2, n) - 1;
        vector<vector<int>> grid(perm + 1, vector<int>(n, 0));
        for (int i = 0; i <= perm; i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) >= 1) {
                    grid[i][j] = 1;
                }
            }
        }
        int mx = 0;
        for (int i = 0; i <= perm; i++) {
            int cnt = 0, temp = 0;
            unordered_set<int> st;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    st.insert(j);
                    cnt++;
                }
            }
            if (cnt == cols) {
                for (int i = 0; i < m; i++) {
                    bool flag = false;
                    for (int j = 0; j < n; j++) {
                        if (st.count(j) == 0) {
                            if (mat[i][j] == 1) {
                                flag = true;
                            }
                        }
                    }
                    if (!flag) temp++;
                }
            }
            mx = max(mx, temp);
        }
        return mx;
    }
};
