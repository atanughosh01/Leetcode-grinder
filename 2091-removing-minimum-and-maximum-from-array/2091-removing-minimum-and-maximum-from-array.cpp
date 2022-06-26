class Solution {
public:
    int minimumDeletions(vector<int> &nums) {
        int n = (int)(nums.size());
        int mx = INT_MIN, mn = INT_MAX;
        int max_idx = -1, min_idx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                max_idx = i;
            }
            if (nums[i] < mn) {
                mn = nums[i];
                min_idx = i;
            }
        }
        int lcnt_max = max_idx + 1, rcnt_max = n - max_idx;
        int lcnt_min = min_idx + 1, rcnt_min = n - min_idx;
        int mn1 = min(max(lcnt_max, lcnt_min), (lcnt_max + rcnt_min));
        int mn2 = min(max(rcnt_max, rcnt_min), (lcnt_min + rcnt_max));
        return min(mn1, mn2);
    }
};
