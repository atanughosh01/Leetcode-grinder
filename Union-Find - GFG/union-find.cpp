// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/union-find/1



class Solution {
private:
    int findPar(int a, int par[]) {
        if (a == par[a])
            return a;
        return par[a] = findPar(par[a], par);
    }
public:
    void union_( int a, int b, int par[], int rank1[]) {
        a = findPar(a, par);
        b = findPar(b, par);
        if (rank1[a] > rank1[b]) {
            par[b] = a;
        } else if (rank1[a] < rank1[b]) {
            par[a] = b;
        } else {
            par[a] = b;
            rank1[b]++;
        }
    }
    
    bool isConnected(int x,int y, int par[], int rank1[]) {
        return findPar(x, par) == findPar(y, par);
    }
};




// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends