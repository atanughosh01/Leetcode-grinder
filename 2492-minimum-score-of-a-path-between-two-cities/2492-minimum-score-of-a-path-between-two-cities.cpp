class Solution_1 {
public:
    int minScore(int n, vector<vector<int>> &roads) {
        queue<vector<int>> q2;
        queue<pair<int, int>> q;
        vector<int> vis(n + 2, 0);
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        q.push({n, INT_MAX});
        int res = INT_MAX;
        while (!q.empty()) {
            auto topElm = q.front();
            q.pop();
            int node = topElm.first;
            int currScore = topElm.second;
            res = min(res, currScore);
            vis[node] = 1;
            for (auto &elm : adj[node]) {
                if (!vis[elm.first]) {
                    q.push({elm.first, elm.second});
                }
            }
        }
        return res;
    }
};



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
        return res;
    }
};
