// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/find-all-possible-paths-from-top-to-bottom/1



class Solution {
private:
    vector<vector<int>> ans;
    void solve(int i, int j, int n, int m, vector<vector<int>> &grid, vector<int> &temp) {
        if (i == n or j == m) return;
        temp.push_back(grid[i][j]);
        if (i == n - 1 and j == m - 1) {
            ans.push_back(temp);
            return;
        }
        if (j == m - 1 and i < n - 1) {
            solve(i + 1, j, n, m, grid, temp);
            temp.pop_back();
        }
        if (i == n - 1 and j < m - 1) {
            solve(i, j + 1, n, m, grid, temp);
            temp.pop_back();
        }
        if (i < n - 1 and j < m - 1) {
            solve(i + 1, j, n, m, grid, temp);
            temp.pop_back();
            solve(i, j + 1, n, m, grid, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid) {
        vector<int> temp;
        solve(0, 0, n, m, grid, temp);
        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends