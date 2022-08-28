int rowIdx[500], colIdx[500];

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {
        int n = rowConditions.size(), m = colConditions.size();
        fill(rowIdx, rowIdx + k + 1, 0);
        fill(colIdx, colIdx + k + 1, 0);
        vector<vector<int>> rGraph(k + 1), cGraph(k + 1);
        for (int i = 0; i < n; i++) {
            rowIdx[rowConditions[i][1]]++;
            rGraph[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for (int i = 0; i < m; i++) {
            colIdx[colConditions[i][1]]++;
            cGraph[colConditions[i][0]].push_back(colConditions[i][1]);
        }
        queue<int> cq, rq;
        for (int i = 1; i <= k; i++) {
            if (rowIdx[i] == 0) rq.push(i);
            if (colIdx[i] == 0) cq.push(i);
        }
        vector<int> rows(k + 1), cols(k + 1);
        int cnt = 0;
        while (!cq.empty()) {
            int i = cq.front();
            cq.pop();
            cols[i] = cnt++;
            for (int j : cGraph[i]) {
                colIdx[j]--;
                if (colIdx[j] == 0) {
                    cq.push(j);
                }
            }
        }
        if (cnt != k) return {};
        cnt = 0;
        while (!rq.empty()) {
            int i = rq.front();
            rq.pop();
            rows[i] = cnt++;
            for (int j : rGraph[i]) {
                rowIdx[j]--;
                if (rowIdx[j] == 0) {
                    rq.push(j);
                }
            }
        }
        if (cnt != k) return {};
        vector<vector<int>> res(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            res[rows[i]][cols[i]] = i;
        }
        return res;
    }
};
