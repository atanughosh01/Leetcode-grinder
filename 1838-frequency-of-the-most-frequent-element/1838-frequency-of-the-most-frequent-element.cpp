class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        long long windowSum = 0;
        int l = 0, r = 0, res = 0;
        sort(nums.begin(), nums.end());
        while (l <= r && r < nums.size()) {
            windowSum += nums[r];
            while (nums[r] * 1ll * (r - l + 1) > k + windowSum) {
                windowSum -= nums[l++];
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
