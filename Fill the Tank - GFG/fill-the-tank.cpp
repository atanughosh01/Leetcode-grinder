// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/fill-the-tank3026/1



class Solution {
private:
    const long long tmp = 1e18;
    bool p = false;
    long long dfs(int curr, vector<vector<long long>> &adj, vector<bool> &vis, int *cap) {
        vis[curr] = true;
        long long mx = 0, l = 0;
        for (auto num : adj[curr]) {
            if (!vis[num]) {
                l++;
                mx = max(mx, dfs(num, adj, vis, cap));
                if (l * mx > tmp) {
                    p = true;
                    return -1;
                }
            }
        }
        return (cap[curr - 1] + mx * l);
    }
public:
    long long minimum_amount(vector<vector<int>> &edges, int num, int start, int *cap) {
        vector<vector<long long>> adj(num + 1);
        vector<bool> vis(num + 1, false);
        for (int i = 0; i < edges.size() - 1; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long t = dfs(start, adj, vis, cap);
        if (p || t > tmp) return -1;
        return t;
    }
};



// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends