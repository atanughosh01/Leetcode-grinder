
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;
        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};

    
/*
    class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            int n = 10001;
            vector<int> sum(n, 0);
            vector<int> dp(n, 0);
            for(auto num: nums)
                sum[num] += num;
            dp[0] = 0;
            dp[1] = sum[1];
            for(int i=2; i<n; i++){
                dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
            }
            return dp[n-1];
        }
    };
*/
