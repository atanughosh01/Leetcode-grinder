class Solution {
   public:
    vector<int> findOrder(int n, vector<vector<int>> &prq) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), res;
    
        for (auto &x : prq) {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        // Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
    
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (auto &child : graph[curr]) {
                if (--indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        return res.size() == n ? res : vector<int>();
    }
};
