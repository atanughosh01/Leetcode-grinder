#define ll long long

class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        int l = 0, r = 0, res = 0;
        ll windowSum = 0;
        sort(nums.begin(), nums.end());
        while (l <= r && r < nums.size()) {
            windowSum += (ll)nums[r];
            while (nums[r] * 1ll * (r - l + 1) - windowSum > (ll)k) {
                windowSum -= (ll)nums[l];
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
