class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n - 1; i++) {
            int maxi = nums[i], mini = nums[i];
            for (int j = i + 1; j < n; j++) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                res += maxi - mini;
            }
        }
        return res;
    }
};
