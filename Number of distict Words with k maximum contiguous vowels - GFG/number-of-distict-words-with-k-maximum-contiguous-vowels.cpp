// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1



#define ll long long
const int MOD = 1e9 + 7;

class Solution {
public:
    int kvowelwords(int n, int k) {
        vector<vector<ll>> dp(n+1, vector<ll> (k+1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                if(i == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][k] * 21 % MOD;
                    if(j > 0) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1] * 5 % MOD) % MOD;
                    }
                }
            }
        }
        return dp[n][k];
    }
};



// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends