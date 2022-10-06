class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int n  = nums.size(), mi = nums[k], res = nums[k];
        for (int i = k, j = k; i >= 0 || j < n;) {
            while (j < n && nums[j] >= mi) j++;
            while (i >= 0 && nums[i] >= mi) i--;
            res = max(res, mi * (j - i - 1));
            if (i >= 0 && j < n) mi = max(nums[i], nums[j]);
            else if (j < n) mi = nums[j];
            else if (i >= 0) mi = nums[i];
        }
        return res;
    }
};
