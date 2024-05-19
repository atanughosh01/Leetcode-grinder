class Solution {
private:
    vector<int> vis, col;
    bool dfs(int v, int c, vector<vector<int>> &graph) {
        vis[v] = 1;
        col[v] = c;
        for (int child : graph[v]) {
            if ((vis[child] == 0 && !dfs(child, c^1, graph)) || col[v] == col[child]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vis.resize(n);
        col.resize(n);
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && !dfs(i, 0, graph)) {
                return false;
            }
        }
        return true;
    }
};
