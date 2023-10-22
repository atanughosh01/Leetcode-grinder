class Solution_1 {
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



class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size(), left = k, right = k;
        int ans = nums[k], currMin = nums[k];
        while (left > 0 || right < n - 1) {
            if ((left > 0 ? nums[left - 1]: 0) < (right < n - 1 ? nums[right + 1] : 0)) {
                right++;
                currMin = min(currMin, nums[right]);
            } else {
                left--;
                currMin = min(currMin, nums[left]);
            }
            ans = max(ans, currMin * (right - left + 1));
        }
        return ans;
    }
};
