// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/spidey-sense5556/1


class Solution{
private:
    vector<vector<int>> visited;
    int helper(vector<vector<char>>& matrix, int M, int N, int i, int j){
        if(i<0 or j<0 or i>=M or j>=N or matrix[i][j] == 'W' or visited[i][j] == 1){
            return 1e6+1;
        }
        if(matrix[i][j] == 'B'){
            return 0;
        }
        visited[i][j] = 1;
        int u = 1 + helper(matrix, M, N, i-1, j);
        int r = 1 + helper(matrix, M, N, i, j+1);
        int d = 1 + helper(matrix, M, N, i+1, j);
        int l = 1 + helper(matrix, M, N, i, j-1);
        visited[i][j] = 0;
        return min(u, min(r, min(d, l)));
    }

public:
    vector<vector<int>> findDistance(vector<vector<char>>& matrix, int M, int N) { 
        vector<vector<int>> res(M, vector<int>(N, 0));
        visited.resize(M, vector<int>(N, 0));
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(matrix[i][j] == 'O'){
                    res[i][j] = helper(matrix, M, N, i, j) >= 1e6 ? -1 : helper(matrix, M, N, i, j);
                }
                else if(matrix[i][j] == 'W'){
                    res[i][j] = -1;
                }
                else{
                    res[i][j] = 0;
                }
            }
        }
        return res;
    } 
};


// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends