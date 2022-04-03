// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/find-the-maximum-flow2126/1


/*
    class Solution {
    private:
        int flow_cap = 0;
        void recurr(int s, int d, vector<vector<int>>& Edges, int flow, bool visited[]){
            if(s==d){
               flow_cap+=flow;
               return;
            }
            for(int i=0;i<Edges.size();i++){
                if((visited[Edges[i][0]]==0&&Edges[i][0]==s)){
                    visited[Edges[i][0]]=1;
                    recurr(Edges[i][1],d,Edges,min(flow,Edges[i][2]),visited);
                    visited[Edges[i][0]]=0;
                   
                }
                if(visited[Edges[i][1]]==0&&Edges[i][1]==s){
                    visited[Edges[i][1]]=1;
                    recurr(Edges[i][0],d,Edges,min(flow,Edges[i][2]),visited);
                    visited[Edges[i][1]]=0;
                   
                }
            }
        }
    public:
        int solve(int N,int M,vector<vector<int>> Edges) {
            bool visited[N];
            sort(Edges.begin(),Edges.end());
            for(int i=0;i<N;i++) visited[i]=0;
            recurr(1,N,Edges,INT_MAX,visited);
            return flow_cap;
        }
    };
*/



class Solution {
private:
    int BFS(vector<vector<int>> &graph,vector<int> &parent,int source,int sink,int N) {
       int min_cap=INT_MAX;
       fill(parent.begin(), parent.end(), -1);
       vector<bool> visited(N,false);
       queue<int> q;
       q.push(source);
       visited[source]=true;
       parent[source]=-1;
       while(!q.empty()) {
           auto u=q.front();
           q.pop();
           for(int v=0;v<N;v++) {
               if(visited[v]==false && graph[u][v]!=0) {
                   if(v==sink) {
                       parent[v]=u;
                       min_cap=min(min_cap,graph[u][v]);
                       return min_cap;
                   }
                   q.push(v);
                   visited[v]=true;
                   min_cap=min(min_cap,graph[u][v]);
                   parent[v]=u;
               }
           }
       }
       return 0;
   }
   int fordFulkerson(vector<vector<int>> &graph,int source,int sink,int N) {
       vector<int> parent(N,-1);
       int res=0;
       while(BFS(graph,parent,source,sink,N)!=0) {
           int min_cap=BFS(graph,parent,source,sink,N);
           res+=min_cap;int v=sink;
           while(v!=source) {
               int u=parent[v];
               graph[u][v]-=min_cap;
               graph[v][u]+=min_cap;
               v=parent[v];
           }
       }
       return res;
   }
public:
   int solve(int N,int M,vector<vector<int>> Edges) {
       vector<vector<int>> graph;
       for(int i=0;i<N;i++) {
           vector<int> v1;
           for(int j=0;j<N;j++) {
               v1.push_back(0);
           }
           graph.push_back(v1);
       }
       for(auto x : Edges) {
           int u=x[0]-1, v=x[1]-1, wt=x[2];
           graph[u][v]+=wt;
           graph[v][u]+=wt;
       }
       return fordFulkerson(graph,0,N-1,N);
   }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int i,j,N,M,u,v,w;
        int res;
        scanf("%d %d",&N,&M);
        vector<vector<int>> Edges; 
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
        	Edges.push_back({u,v,w});
    	}
        Solution obj;
        res = obj.solve(N, M, Edges);
        cout<<res<<endl;
    }
    return 0;
}  // } Driver Code Ends