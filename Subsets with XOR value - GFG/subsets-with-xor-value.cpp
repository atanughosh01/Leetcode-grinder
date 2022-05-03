// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/subsets-with-xor-value2023/1



class Solution {
private:
    int solve(int idx, int n, int Xor, int K, vector<int> &arr, vector<vector<int>> &dp) {
        if (idx == n) {
            if (Xor == K)
                return 1;
            return 0;
        }
        if (dp[idx][Xor] != -1)
            return dp[idx][Xor];
        int ans1 = solve(idx + 1, n, Xor, K, arr, dp);
        int ans2 = solve(idx + 1, n, Xor ^ arr[idx], K, arr, dp);
        return (dp[idx][Xor] = ans1 + ans2);
    }
public:
    int subsetXOR(vector<int> &arr, int N, int K) {
        vector<vector<int>> dp(N, vector<int>(129, -1));
        return solve(0, N, 0, K, arr, dp);
    }
};



// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends