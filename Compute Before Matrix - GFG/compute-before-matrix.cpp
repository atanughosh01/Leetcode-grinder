// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/85781966a9db2a1ac17eaaed26a947eba5740d56/1



class Solution{
public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        vector<vector<int>> v(N,vector<int>(M,0));
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int j=0;j<M;j++){
                if(i==0 && j==0) v[i][j] = after[i][j];
                else if(i==0) v[i][j] =after[i][j] - after[i][j-1];
                else if(j==0) v[i][j] =after[i][j] - after[i-1][j];
                else v[i][j] = after[i][j] - after[i-1][j] - sum;
                sum+=v[i][j];
            }
        }
        return v;
    }
};



// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends