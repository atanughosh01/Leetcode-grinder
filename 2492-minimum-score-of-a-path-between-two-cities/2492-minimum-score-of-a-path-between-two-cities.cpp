class Solution {
public:
    int minScore(int n, vector<vector<int>> &roads) {
        queue<pair<int, int>> q;
        vector<int> dist(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        dist[1] = 0;
        q.push({1, INT_MAX});
        int res = INT_MAX;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto topElm = q.front();
                q.pop();
                int node = topElm.first;
                int currScore = topElm.second;
                for (auto &it : adj[node]) {
                    int newNode = it.first;
                    int newDist = it.second;
                    newDist = min(newDist, currScore);
                    if (newDist < dist[newNode]) {
                        dist[newNode] = newDist;
                        res = min(res, newDist);
                        q.push({newNode, newDist});
                    }
                }
            }
        }
        return res;
    }
};
