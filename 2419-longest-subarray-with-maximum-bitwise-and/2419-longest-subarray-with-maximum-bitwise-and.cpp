class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int res = 0, cur = 0;
        for (int &x : nums) {
            if (x == mx) cur++;
            else cur = 0;
            res = max(res, cur);
        }
        return res;
    }
};
