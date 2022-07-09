class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = (int)(nums.size());
        if (n <= 1) return n;
        int max_len = 1, cur_len = min(1, n);
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] - nums[i - 1] == 1) cur_len++;
            else {
                max_len = max(max_len, cur_len);
                cur_len = 1;
            }
        }
        return max(max_len, cur_len);
    }
};
