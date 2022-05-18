/*
    class Solution {
    private:
        vector<int> disc{0}, low{0};
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
*/


class Solution {
private:
    vector<vector<int>> ans, graph;
    vector<int> firstTime, minTime, visited;
    int time = 1;
    void dfs(int node, int parent = -1) {
        firstTime[node] = minTime[node] = time++;
        visited[node] = true;
        for (auto &child : graph[node]) {
            if (child == parent) continue;
            if (!visited[child]) dfs(child, node);
            minTime[node] = min(minTime[child], minTime[node]);
            if (firstTime[node] < minTime[child]) ans.push_back({node, child});
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        firstTime.resize(n), minTime.resize(n), visited.resize(n), graph.resize(n);
        for (auto &edge : connections) {
            int nodeA = edge[0], nodeB = edge[1];
            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }
        dfs(0);
        return ans;
    }
};
