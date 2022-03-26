class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<n/2; i++) {
            int pairSum = nums[i] + nums[n-i-1];
            ans = max(ans, pairSum);
        }
        return ans;
    }
};
