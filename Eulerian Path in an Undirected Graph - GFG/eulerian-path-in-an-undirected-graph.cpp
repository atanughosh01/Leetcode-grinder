// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/eulerian-path-in-an-undirected-graph5052/1



class Solution{
public:
    int eulerPath(int N, vector<vector<int>> &graph){
        vector<int> degree(N,0);
        for(int i=0; i<N; ++i) {
            int count = 0;
            for(int j=0; j<N; ++j) {
                if(graph[i][j] == 1)
                    count++;
            }
           degree[i] = count;
        }
        int oddVertex = 0;
        for(int i=0; i<N; ++i) {
            if(degree[i]%2)
                oddVertex++;
        }
       return (oddVertex == 2 ? 1 : 0);
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                cin>>graph[i][j];
        
        Solution ob;
        cout<<ob.eulerPath(N, graph)<<"\n";
    }
    return 0;
}  // } Driver Code Ends