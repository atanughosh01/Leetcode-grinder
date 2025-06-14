// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/count-the-paths4332/1



class Solution {
private:
    int ans = 0;
    void dfs(int s, int d, vector<int> ad[], vector<int> &vis) {
        if (s == d) {
            ans++;
            return;
        }
        if (vis[s] == -1) {
            vis[s] = 1;
        } else {
            return;
        }
        for (auto i : ad[s]) {
            if (vis[i] == -1) {
                dfs(i, d, ad, vis);
            }
        }
        vis[s] = -1;
    }
public:
    int possible_paths(vector<vector<int>> &edges, int n, int s, int d) {
        vector<int> vis(n, -1);
        vector<int> ad[n];
        for (auto &edge : edges) {
            ad[edge[0]].push_back(edge[1]);
        }
        dfs(s, d, ad, vis);
        return ans;
    }
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends