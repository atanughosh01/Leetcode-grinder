// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/number-of-ways2552/1



class Solution {
private:
    long long solve(int n, vector<long long> &dp) {
        if (n < 4) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 4, dp);
    }
public:
    long long arrangeTiles(int n) {
        vector<long long> dp(n + 1, -1);
        return solve(n, dp);
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends