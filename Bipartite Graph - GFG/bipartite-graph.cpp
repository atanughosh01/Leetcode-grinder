// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/bipartite-graph/1



class Solution {
private:
    bool check = true;
    void dfs(int v, int p, int col, vector<int> &vis, vector<int> adj[]) {
        if (!check) return;
        vis[v] = col;
        for (auto to : adj[v]) {
            if (to == p) continue;
            if (!vis[to])
                dfs(to, v, 3 - col, vis, adj);
            else if (vis[to] == col) {
                check = false;
                return;
            }
        }
    }
public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, 1, vis, adj);
            }
        }
        return check;
    }
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends