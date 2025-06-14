class SparseTable {
private:
    int n, log;
    vector<vector<int>> grid;
public:
    SparseTable(int _n) {
        n = _n;
        log = (int)log2(n);
        grid.resize(n, vector<int>(log + 1));
    }
    void createTable(vector<int> &arr) {
        for (int i = 0; i < n; i++) {
            grid[i][0] = arr[i];
        }
        for (int k = 1; k <= log; k++) {
            for (int i = 0; i < n; i++) {
                if (i + (1 << (k - 1)) < n) {
                    grid[i][k] = max(grid[i][k - 1], grid[i + (1 << (k - 1))][k - 1]);
                } else {
                    grid[i][k] = grid[i][k - 1];
                }
            }
        }
    }
    int Query(int L, int R) {
        int k = (int)log2(R - L + 1);
        return max(grid[L][k], grid[R - (1 << k) + 1][k]);
    }
};

class Solution {
private:
    vector<long long> pref;
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
        int n = chargeTimes.size();
        SparseTable st(n);
        st.createTable(chargeTimes);
        pref.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + runningCosts[i - 1];
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int i = 0, j = mid;
            bool flag = false;
            while (j < n) {
                long long sum = (st.Query(i, j) + (mid + 1) * (pref[j + 1] - pref[i]));
                flag |= (sum <= budget);
                i++, j++;
            }
            if (flag) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
