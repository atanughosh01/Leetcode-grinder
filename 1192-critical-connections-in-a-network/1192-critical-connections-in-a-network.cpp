class Solution {
private:
    vector<int> disc, low;
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
    void dfs(int curr, int prev) {
        disc[curr] = low[curr] = time++;
        for (int next : edgeMap[curr]) {
            if (disc[next] == 0) {
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } else if (next != prev) {
                low[curr] = min(low[curr], disc[next]);
            }
            if (low[next] > disc[curr]) {
                ans.push_back({curr, next});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        disc.resize(n);
        low.resize(n);
        for (auto conn : connections) {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }
};
