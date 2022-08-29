class Solution {
public:
    bool canFinish(int n, vector<vector<int>> &p) {
        if (p.empty()) return true;

        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);

        for (vector<int> &x : p) {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                indegree[i]--;
            }
        }
        if (q.empty()) return false;

        int count = 0;
        while (!q.empty()) {
            for (int i = 0; i < q.size(); i++) {
                int curr = q.front();
                q.pop();
                count++;
                for (int child : graph[curr]) {
                    indegree[child]--;
                    if (indegree[child] == 0) {
                        q.push(child);
                    }
                }
            }   
        }
        return count == n;
    }
};
