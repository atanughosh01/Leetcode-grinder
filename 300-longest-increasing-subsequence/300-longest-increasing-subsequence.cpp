class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> LIS;
        for (int i = 0; i < nums.size(); i++) {
            if (LIS.size() == 0 || LIS[LIS.size() - 1] < nums[i]) {
                LIS.push_back(nums[i]);
            } else {
                int l = 0, r = LIS.size() - 1;
                while (l < r) {
                    int m = l + (r - l) / 2;
                    if (LIS[m] >= nums[i]) {
                        r = m;
                    } else {
                        l = m + 1;
                    }
                }
                LIS[l] = nums[i];
            }
        }
        return LIS.size();
    }
};
