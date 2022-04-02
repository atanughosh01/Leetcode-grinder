class Solution {
public:
	int triangularSum(vector<int>& nums) {
		int n = (int)nums.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++) {
            dp[n-1][i] = nums[i];
        }
        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<=i; j++) {
                dp[i][j] = (dp[i+1][j] + dp[i+1][j+1]) % 10;
            }
        }
        return dp[0][0]; 
	}
};
