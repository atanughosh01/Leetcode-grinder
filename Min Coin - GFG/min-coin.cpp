// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/min-coin5549/1



class Solution{
public:
	int MinCoin(vector<int> &nums, int amount) {
	    vector<int> dp(amount+2, amount+5);
        dp[0]=0;
        int n=nums.size();
        for(int i=1; i<amount+1; i++) {
            for(int j=0; j<n; j++) {
                if(nums[j] <= i) {
                    dp[i] = min(dp[i], 1+dp[i-nums[j]]);
                }
            }
        }
        return ((dp[amount] > amount) ? -1 : dp[amount]);
	}
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends