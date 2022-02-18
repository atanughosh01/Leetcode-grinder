// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1


class Solution {
 private:
    void dfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j]='0';
        if(i>0 && grid[i-1][j]=='1')
            dfs(i-1,j,grid);
        if(j>0 && grid[i][j-1]=='1')    
            dfs(i,j-1,grid);
        if(i<grid.size()-1 && grid[i+1][j]=='1')    
            dfs(i+1,j,grid);
        if(j<grid[0].size()-1 && grid[i][j+1]=='1')    
            dfs(i,j+1,grid);
        if(j>0 && i>0 && grid[i-1][j-1]=='1')    
            dfs(i-1,j-1,grid);
        if(i>0 && j<grid[0].size()-1 && grid[i-1][j+1]=='1')    
            dfs(i-1,j+1,grid);
        if(i<grid.size()-1 && j>0 && grid[i+1][j-1]=='1')    
            dfs(i+1,j-1,grid);
        if(i<grid.size()-1 && j<grid[0].size()-1 && grid[i+1][j+1]=='1')    
            dfs(i+1,j+1,grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends