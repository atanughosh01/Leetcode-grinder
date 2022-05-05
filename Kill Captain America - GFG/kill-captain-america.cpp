// { Driver Code Starts
#include <bits/stdc++.h>
 
using namespace std;
 

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/kill-captain-america0228/1



class Solution {
private:
    void make_graph(vector<vector<int>> &V, vector<int> *adj, vector<int> *trans_adj) {
        for (int i = 0; i < V.size() - 1; i++) {
            adj[V[i][0]].push_back(V[i][1]);
            trans_adj[V[i][1]].push_back(V[i][0]);
        }
        return;
    }

    int outdeg(unordered_set<int> st, vector<int> *adj) {
        int out = 0;
        for (auto i : st) {
            for (int child : adj[i]) {
                if (st.find(child) == st.end()) out++;
            }
        }
        return out;
    }

    void topo_dfs(int node, vector<int> *adj, vector<int> &vis, stack<int> &st) {
        vis[node] = true;
        for (auto i : adj[node]) {
            if (!vis[i]) {
                topo_dfs(i, adj, vis, st);
            }
        }
        st.push(node);
        return;
    }

    void dfs(int node, vector<int> *adj, vector<int> &vis, unordered_set<int> &sett) {
        vis[node] = true;
        sett.insert(node);
        for (auto i : adj[node]) {
            if (!vis[i]) {
                dfs(i, adj, vis, sett);
            }
        }
        return;
    }
    
public:
    int captainAmerica(int N, int M, vector<vector<int>> &V) {
        int out_0 = 0, max_size = INT_MIN;
        vector<int> adj[N + 1], vis(N + 1, false), trans[N + 1];
        stack<int> st;
        make_graph(V, adj, trans);
        for (int i = 1; i < N + 1; i++) {
            if (!vis[i]) {
                topo_dfs(i, adj, vis, st);
            }
        }
        for (int i = 0; i < N + 1; i++) {
            vis[i] = false;
        }
        while (!st.empty()) {
            unordered_set<int> sett;
            if (!vis[st.top()]) {
                dfs(st.top(), trans, vis, sett);
                if (outdeg(sett, adj) == 0) {
                    int size = sett.size();
                    max_size = max(max_size, size);
                    out_0++;
                }
            }
            st.pop();
        }
        if (out_0 > 1) return 0;
        return max_size;
    }
};




// { Driver Code Starts.
 

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m+1);
        for(int i=0;i<m;i++){
            int a, b;cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }
        
        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }
 
}  // } Driver Code Ends