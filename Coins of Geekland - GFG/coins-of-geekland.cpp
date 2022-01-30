// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/257a9e27fb3e58255622c8dcb06e0919cc1c6c11/1


class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>>& mat,int N,int K){
         for(int i=0;i<N;i++) {
             for(int j=0;j<N;j++) {   
                 if(i-1>=0)
                 mat[i][j]+=mat[i-1][j];
                 if(j-1>=0)
                 mat[i][j]+=mat[i][j-1];
                 if(i-1>=0 && j-1>=0)
                 mat[i][j]-=mat[i-1][j-1];
             }
         }
          int ans =INT_MIN;
          for(int i=0;i<N;i++) {
             for(int j=0;j<N;j++) {  
                 int local = mat[i][j];
                 if(i-K>=0)
                 local-=mat[i-K][j]; 
                 if(j-K>=0)
                 local-=mat[i][j-K]; 
                 if(i-K>=0 && j-K>=0)
                 local+=mat[i-K][j-K];
                 ans = max(ans,local);
             }
         }
         return ans;
    }  
};


// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends