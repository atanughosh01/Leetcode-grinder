// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/nodes-at-even-distance0532/1



class Solution{
private:
    void dfs(vector<int> graph[],bool v[],int &c,int l,int x) {
        v[l] = true;
        if (x % 2) c++;
        for (auto it : graph[l]) {
            if(!v[it])
                dfs(graph,v,c,it,x+1);
        }
    }
public:
    int countOfNodes(vector<int> graph[], int n) {
        bool v[n+1] = {0};
        int c = 0;
        dfs(graph,v,c,1,0);
        return c*(c-1)/2 + (n - c)*(n - c -1)/2;
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends