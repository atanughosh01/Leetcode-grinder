// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problems : https://practice.geeksforgeeks.org/problems/broken-blocks0022/1



class Solution {
public:
    int solve(vector<vector<int>> &A, int i, int j, vector<vector<int>> &dp) {
        if (i==A.size() || j<0 || j==A[0].size() || A[i][j]==-1) return 0;
        int a=0, b=0, c=0;
        if (dp[i][j] != -1) return dp[i][j];
        a = A[i][j] + solve(A, i+1, j, dp);
        b = A[i][j] + solve(A, i+1, j-1, dp);
        c = A[i][j] + solve(A, i+1, j+1, dp);
        return dp[i][j] = max({a, b, c});
    }
    int MaxGold(vector<vector<int>> &A) {
        int m = A.size(), n = A[0].size(), res=0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i=0; i<n; i++){
            res = max(res, solve(A, 0, i, dp));
        }
        return res;
    }
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends