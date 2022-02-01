// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dis(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        dis[S] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto it : adj[u]){
                int v = it[0];
                int w = it[1];
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
           	}
       }
       return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends