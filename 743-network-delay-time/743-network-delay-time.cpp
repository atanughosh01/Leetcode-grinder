class Solution {
   public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        vector<pair<int, int>> g[N + 1];
        for (int i = 0; i < times.size(); i++) {
            g[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        vector<int> dist(N + 1, 1e9);
        dist[K] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, K));
        pair<int, int> temp;
        bool vis[N + 1];
        memset(vis, false, sizeof(vis));
        while (!pq.empty()) {
            temp = pq.top();
            pq.pop();
            int u = temp.second;
            vis[u] = true;
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i].first;
                int weight = g[u][i].second;
                if (!vis[v] && (dist[v] > dist[u] + weight)) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < dist.size(); i++) {
            ans = max(ans, dist[i]);
        }
        if (ans == 1e9) return -1;
        return ans;
    }
};
