// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/biconnected-graph2528/1



class Solution {
public:
    int biGraph(int arr[], int n, int e) {
        if(n==1) return 1;
        if(n==2 && e==1) return 1;
        vector<int> g[n];
        for(int i=0; i<2*e; i+=2) {
           int u = arr[i];
           int v = arr[i+1];
           g[u].push_back(v);
           g[v].push_back(u);
        }
        for(auto i : g){
            if(i.size()<2) {
                return 0;
            }   
        }
       return 1;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends