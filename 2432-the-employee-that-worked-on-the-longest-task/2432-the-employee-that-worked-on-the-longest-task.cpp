class Solution {
public:
    int hardestWorker(int n, vector<vector<int>> &logs) {
        int d = logs[0][1], id = logs[0][0], N = logs.size();
        for (int i = 1; i < N; i++) {
            int ans = logs[i][1] - logs[i - 1][1];
            if (ans == d) id = min(id, logs[i][0]);
            if (ans > d) {
                d = ans;
                id = logs[i][0];
            }
        }
        return id;
    }
};
