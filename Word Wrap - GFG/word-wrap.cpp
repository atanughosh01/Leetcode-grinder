// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/word-wrap1646/1



class Solution {
public:
    int solveWordWrap(vector<int>& nums, int k)  {
        vector<vector<int>> dp(nums.size(), vector<int> (k+1, 0));
        int n = (int)(nums.size());
        for(int i=0; i<=nums[n-1]; i++)
        dp[n-1][i] = i*i;
        for(int ind=n-2; ind>=0; ind--) {
            for(int rl=0; rl<=k; rl++) {
                if(nums[ind]<rl) {
                    int take = dp[ind+1][rl==k ? rl-nums[ind] : rl-nums[ind]-1];
                    int notTake = rl*rl + dp[ind+1][k-nums[ind]];
                    dp[ind][rl] = min(take,notTake);
                } else {
                    dp[ind][rl] = rl*rl + dp[ind+1][k-nums[ind]];
                }
            }
        }
        return dp[0][k];
    } 
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends