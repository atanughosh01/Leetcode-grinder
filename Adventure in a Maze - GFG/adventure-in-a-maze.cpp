// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/adventure-in-a-maze2051/1



class Solution {
private:
    const int mod = 1000000007;
    pair<int, int> solve(vector<vector<int>> &a, int i, int j, int &n, int &m, vector<vector<pair<int, int>>> &dp) {
        if(i>=n || j>=m) return {0, 0};
        if(i==n-1 && j==m-1) return dp[i][j] = {1, a[i][j]};
        if(dp[i][j].first != -1) return dp[i][j];
        pair<int, int> ans = {0, 0};
        if(a[i][j]==1 || a[i][j]==3){
            auto p = solve(a, i, j+1, n, m, dp);
            if(p.first>0){
                ans.first += p.first;
                ans.first %= mod;
                if((p.second+a[i][j])>ans.second){
                    ans.second = p.second+a[i][j];
                }
            }
        }
        if(a[i][j]==2 || a[i][j]==3){
            auto p = solve(a, i+1, j, n, m, dp);
            if(p.first>0){
                ans.first += p.first;
                ans.first %= mod;
                if((p.second+a[i][j])>ans.second){
                    ans.second = p.second+a[i][j];
                }
            }
        }
        return dp[i][j] = ans;
    }
public:
    vector<int> FindWays(vector<vector<int>> &mat){
        int n = mat.size(), m = mat[0].size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {-1, -1}));
        auto p = solve(mat, 0, 0, n, m, dp);
        return {p.first, p.second};
    }
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends