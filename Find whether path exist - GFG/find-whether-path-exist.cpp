// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1



class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool dfs(int x, int y, int destx, int desty, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        if (x == destx && y == desty) return true;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < m && y + dy[i] >= 0 &&
                vis[x + dx[i]][y + dy[i]] == 0 && grid[x + dx[i]][y + dy[i]] != 0) {
                if (dfs(x + dx[i], y + dy[i], destx, desty, n, m, grid, vis))
                    return true;
            }
        }
        return false;
    }
public:
    bool is_Possible(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int src_x = 0, src_y = 0, dest_x = 0, dest_y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    src_x = i;
                    src_y = j;
                } else if (grid[i][j] == 2) {
                    dest_x = i;
                    dest_y = j;
                }
            }
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return dfs(src_x, src_y, dest_x, dest_y, n, m, grid, vis);
    }
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends