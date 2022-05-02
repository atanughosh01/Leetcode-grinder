// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/party-in-town3951/1



class Solution {
private:
    int max_d = 0;
    void dfs(int idx, vector<vector<int>> &adj, vector<int> &vis, int c) {
        vis[idx] = 1;
        max_d = max(max_d, c);
        for (int i : adj[idx]) {
            if (!vis[i]) {
                dfs(i, adj, vis, c + 1);
            }
        }
    }
public:
    int partyHouse(int N, vector<vector<int>> &adj) {
        int mn = INT_MAX, house = -1;
        for (int i = 1; i <= N; i++) {
            vector<int> vis(N + 1, 0);
            max_d = 0;
            dfs(i, adj, vis, 0);
            mn = min(mn, max_d);
        }
        return mn;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends